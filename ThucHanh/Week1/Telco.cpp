#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

class Date
{
public:
    long year;
    long month;
    long day;
    void print()
    {
        cout << year << ":" << month << ":" << day;
    }
    Date() {}
    Date(string date)
    {
        this->year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        this->month = (date[5] - '0') * 10 + (date[6] - '0');
        this->day = (date[8] - '0') * 10 + (date[9] - '0');
    }
    Date(long year, long month, long day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};
class Time
{
public:
    long hour;
    long minute;
    long second;
    void print()
    {
        cout << hour << ":" << minute << ":" << second;
    }
    Time() {}
    Time(string time)
    {
        this->hour = (time[0] - '0') * 10 + (time[1] - '0');
        this->minute = (time[3] - '0') * 10 + (time[4] - '0');
        this->second = (time[6] - '0') * 10 + (time[7] - '0');
    }
    Time(long hour, long minute, long second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
};

class Call
{
public:
    string from_number;
    string to_number;
    Date date;
    Time from_time;
    Time to_time;
    Call() {}
    Call(string from_number, string to_number, Date date, Time from_time, Time to_time)
    {
        this->from_number = from_number;
        this->to_number = to_number;
        this->date = date;
        this->from_time = from_time;
        this->to_time = to_time;
    }
};

/*
Method, function
*/
bool check_phone(string phone)
{
    bool res = true;
    if (phone.length() != 10)
        res = false;
    if (phone[0] != '0')
        res = false;
    for (long i = 1; i <= 9; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            res = false;
    }
    return res;
}

long countTime(Time from_time, Time to_time)
{
    return 3600 * (to_time.hour - from_time.hour) + 60 * (to_time.minute - from_time.minute) + (to_time.second - from_time.second);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type, from_time, to_time, date;
    int totalCall = 0;
    int correctCall = 0;
    map<string, long> timePhone;
    vector<Call> calls;
    Call call;
    // do
    // {
    // cin >> type;
    // if (type == "#")
    //     continue;
    totalCall++;
    cin >> call.from_number >> call.to_number >> date >> from_time >> to_time;
    call.date = Date(date);
    call.from_time = Time(from_time);
    call.to_time = Time(to_time);
    cout << call.from_number << " " << call.to_number;
    call.date.print();
    call.from_time.print();
    call.to_time.print();
    // } while (type != "#");
    // do
    // {
    //     cin >> type;
    //     if (type != "#")
    //         continue;
    //     else if ()
    // } while (type != "#");
}
