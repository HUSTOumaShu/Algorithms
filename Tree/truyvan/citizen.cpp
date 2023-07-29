#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

/*
Initialize Date
*/
class Date
{
public:
    int day;
    int month;
    int year;
    Date(){};
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    string toString()
    {
        return to_string(this->day) + "-" + to_string(this->month) + "-" + to_string(this->year);
    }
};
int getIntStr(string str)
{
    return stoi(str);
}
Date getDateStr(string str)
{
    vector<int> date;
    int start = 0, end = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            end = i;
            string temp;
            temp.append(str, start, end - start);
            date.push_back(getIntStr(temp));
            start = end + 1;
        }
        else if (i == str.length() - 1)
        {
            end = i;
            string temp;
            temp.append(str, start, end - start + 1);
            date.push_back(getIntStr(temp));
            start = end + 1;
        }
    }
    Date result = Date(date[2], date[1], date[0]);
    return result;
}

/*
Initialize Person
*/
class Person
{
public:
    string code;
    Date birthday;
    string father;
    string mother;
    string alive;
    string region;
    Person(){};
    Person(string code, Date birthday, string father, string mother, string alive, string region)
    {
        this->code = code;
        this->birthday = birthday;
        this->father = father;
        this->mother = mother;
        this->alive = alive;
        this->region = region;
    }
    string toString()
    {
        return this->code + " " + this->birthday.toString() + " " + this->father + " " + this->mother + " " + this->alive + " " + this->region;
    }
};

Person getPersonStr(string str)
{
    vector<string> info;
    int start = 0, end = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            end = i;
            string temp;
            temp.append(str, start, end - start);
            info.push_back(temp);
            start = end + 1;
        }
        else if (i == str.length() - 1)
        {
            end = i;
            string temp;
            temp.append(str, start, end - start + 1);
            info.push_back(temp);
            start = end + 1;
        }
    }
    string code = info[0];
    Date birthday = getDateStr(info[1]);
    string father = info[2];
    string mother = info[3];
    string alive = info[4];
    string region = info[5];
    Person person = Person(code, birthday, father, mother, alive, region);
    return person;
}

/*
Initialize database
*/
map<string, Person> persons;

/*
Function
*/
int findAncestor(Person person)
{
    if (person.father == "0000000" && person.mother == "0000000")
        return 0;
    return 1 + max(findAncestor(persons[person.mother]), findAncestor(persons[person.father]));
}

/*
Main
*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    do
    {

        tm *ltm;
        getline(cin, type);
        if (type == "*")
            continue;
        Person person = getPersonStr(type);
        persons[person.code] = person;
    } while (type != "*");

    do
    {
        getline(cin, type);
        if (type == "*")
            break;

        if (type == "NUMBER_PEOPLE")
            cout << persons.size() << endl;

        if (type.find("NUMBER_PEOPLE_BORN_AT") < type.length())
        {
            int count = 0;
            int start = strlen("NUMBER_PEOPLE_BORN_AT") + 1;
            int end = type.length() - 1;
            string temp;
            temp.append(type, start, end);
            Date date = getDateStr(temp);
            for (auto it : persons)
            {
                Date datetmp = it.second.birthday;
                if (datetmp.toString() == date.toString())
                    count++;
            }
            cout << count << endl;
        }

        if (type.find("MOST_ALIVE_ANCESTOR") < type.length())
        {
            int start = strlen("MOST_ALIVE_ANCESTOR") + 1;
            int end = type.length() - 1;
            string temp;
            temp.append(type, start, end);
            cout << findAncestor(persons[temp]) << endl;
        }

        if (type.find("NUMBER_PEOPLE_BORN_BETWEEN") < type.length())
        {
            // get two day between and store to fromdate and todate
            int start = strlen("NUMBER_PEOPLE_BORN_BETWEEN") + 1;
            int end = start;
            for (end = start; end < type.length(); end++)
                if (type[end] == ' ')
                    break;
            end--;
            string temp1, temp2;
            temp1.append(type, start, end - start + 1);

            start = end + 2;
            end = type.length() - 1;
            temp2.append(type, start, end - start + 1);

            Date fromdate = getDateStr(temp1);
            Date todate = getDateStr(temp2);

            int count = 0;
            for (auto it : persons)
            {
                Date datetmp = it.second.birthday;
                if (datetmp.year >= fromdate.year && datetmp.year <= todate.year)
                    count++;
                else if (fromdate.year == todate.year)
                {
                    if (datetmp.month >= fromdate.month && datetmp.month <= todate.month)
                        count++;
                    else if (fromdate.month == todate.month)
                    {
                        if (datetmp.day >= fromdate.day && datetmp.day <= todate.day)
                            count++;
                    }
                }
            }
            cout << count << endl;
        }

        if (type == "MAX_UNRELATED_PEOPLE")
        {
        }
    } while (type != "*");
}
