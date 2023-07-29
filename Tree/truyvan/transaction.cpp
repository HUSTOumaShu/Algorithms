#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

int getIntStr(string str)
{
    return stoi(str);
}

/*
Initialize time
*/
class Time
{
public:
    int hour;
    int min;
    int sec;
    Time() {}
    Time(int hour, int min, int sec)
    {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }
    string toString()
    {
        return to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
    }
};

Time getTimeStr(string str)
{
    int start = 0, end = 0;
    vector<string> time;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ':')
        {
            end = i;
            string temp;
            temp.append(str, start, end - start);
            time.push_back(temp);
            start = end + 1;
        }
        else if (i == str.length() - 1)
        {
            end = i;
            string temp;
            temp.append(str, start, end - start + 1);
            time.push_back(temp);
            start = end + 1;
        }
    }
    Time result = Time(getIntStr(time[0]), getIntStr(time[1]), getIntStr(time[2]));
    return result;
}

int getSec(Time time)
{
    return time.hour * 3600 + time.min * 60 + time.sec;
}

class Transaction
{
public:
    string from;
    string to;
    int money;
    Time timepoint;
    string atm;
    Transaction() {}
    Transaction(string from, string to, int money, Time timepoint, string atm)
    {
        this->from = from;
        this->to = to;
        this->money = money;
        this->timepoint = timepoint;
        this->atm = atm;
    }
    string toString()
    {
        return from + " " + to + " " + to_string(money) + " " + timepoint.toString() + " " + atm;
    }
};

Transaction getTransactionStr(string str)
{
    vector<string> info;
    int start = 0, end = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            end = i;
            string temp;
            temp.append(str, start, end - start);
            info.push_back(temp);
            start = end + 1;
        }
        if (i == str.length() - 1)
        {
            end = i;
            string temp;
            temp.append(str, start, end - start + 1);
            info.push_back(temp);
            start = end + 1;
        }
    }
    Transaction transaction = Transaction(info[0], info[1], getIntStr(info[2]), getTimeStr(info[3]), info[4]);
    return transaction;
}

map<string, vector<Transaction>> transactions;
int cycle(string fromfirst, string fromtmp, int num)
{
    if (num == 0)
    {
        if (fromfirst == fromtmp)
            return 1;
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;

    // Input database
    do
    {
        getline(cin, type);
        if (type == "#")
            continue;
        Transaction transaction = getTransactionStr(type);
        transactions[transaction.from].push_back(transaction);

    } while (type != "#");

    // Query
    do
    {
        getline(cin, type);
        if (type == "#")
            break;

        if (type == "?total_money_transaction")
        {
            int result = 0;
            for (auto it : transactions)
                for (auto tran : it.second)
                    result += tran.money;
            cout << result << endl;
        }

        if (type.find("?total_money_transaction_from") < type.length())
        {
            int start = strlen("?total_money_transaction_from") + 1;
            int end = type.length() - 1;
            string fromtmp;
            fromtmp.append(type, start, end - start + 1);
            int result = 0;
            for (auto it : transactions[fromtmp])
                result += it.money;
            cout << result << endl;
        }

        if (type.find("?inspect_cycle") < type.length())
        {
            int start = strlen("?inspect_cycle") + 1;
            int end = start;
            for (end = start; end < type.length(); end++)
                if (type[end] == ' ')
                    break;

            string temp1, temp2;
            temp1.append(type, start, end - start);

            start = end + 1;
            end = type.length() - 1;
            temp2.append(type, start, end - start + 1);

            int num = getIntStr(temp2);
            while (num > 0)
            {
                // TO DO
            }
        }

        if (type.find("?max_money_previod") < type.length())
        {
            // Split string to get time
            int start = strlen("?max_money_previod") + 1;
            int end = start;
            for (end = start; end < type.length(); end++)
                if (type[end] == ' ')
                    break;
            string temp1, temp2;
            temp1.append(type, start, end - start);
            start = end + 1;
            end = type.length() - 1;
            temp2.append(type, start, end - start + 1);
            Time time1 = getTimeStr(temp1);
            Time time2 = getTimeStr(temp2);

            // Process time
            int result = 0;
            for (auto it : transactions)
                for (auto tran : it.second)
                    if (getSec(tran.timepoint) <= getSec(time2) && getSec(tran.timepoint) >= getSec(time1))
                        result = max(result, tran.money);
            cout << result << endl;
        }
    } while (type != "#");
}

// Bài 1, 2, 3:
// T000000005 T000000002 30 06:05:27 atm6
// T000000001 T000000005 20 10:13:45 atm1
// T000000004 T000000005 10 20:43:08 atm1
// T000000001 T000000002 40 06:05:27 atm1
// T000000002 T000000001 60 11:13:40 atm1
// #
// ?total_money_transaction
// ?total_money_transaction_from T000000001
// ?total_money_transaction_from T000000005
// ?inspect_cycle T000000001 3
// ?inspect_cycle T000000004 2
// ?inspect_cycle T000000001 2
// #

// Bài 4:
// T000000005 T000000002 34 06:05:27 atm6
// T000000001 T000000005 90 10:13:45 atm1
// T000000004 T000000005 96 20:43:08 atm1
// T000000005 T000000002 81 06:05:27 atm2
// T000000005 T000000002 11 04:45:38 atm2
// #
// ?max_money_previod 00:00:00 23:59:59
// ?max_money_previod 04:00:20 06:05:26
// ?max_money_previod 06:05:27 10:13:45
