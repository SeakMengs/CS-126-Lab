//Struct (build student input and display student information)
#include <iostream>
using namespace std;

#define maxx 5
string major[3];
struct student
{
    string fname;
    string lname;
    int id;
    int studentgrade;
    int birthday;
    int birthmonth;
    int birthyear;
    string courses[3] = {"CS", "MIS", "BUS"};
} studentinfo[maxx];
student input(student& s)
{
    int n = 0;
    for (int i = 0; i < 1; i++)
    {
    cout << "Enter first name: ";
    getline (cin, s.fname);
    cout << "Enter last name: ";
    getline (cin, s.lname);
    cout << "Enter birthmonth: ";
    cin >> s.birthmonth;
    cout << "Enter birthday: ";
    cin >> s.birthday;
    cout << "Enter birthyear: ";
    cin >> s.birthyear;
    cout << "Enter student id: ";
    cin >> s.id;
    cout << "Enter Major CS = 1, MIS = 2, BUS = 3" << endl;
    cin >> n;
    major[i]= s.courses[n - 1];
    cin.ignore();
    }
    return s;
}
//convert the birthday specific month/day/year to age;
/*int convert_age(int month, int day, int year)
{
    int age;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    age = 1900 + ltm->tm_year - year;
    if (month > 1 && month < 7)
    {
        if (month == 2 && day > 28)
        {
            age--;
        }
        else if (month == 2 && day < 29)
        {
            age++;
        }
    }
    else if (month > 6 && month < 12)
    {
        if (month == 7 && day > 28)
        {
            age--;
        }
        else if (month == 7 && day < 29)
        {
            age++;
        }
    }
    return age;
} */
int convert_age(int month, int day, int year)
{
    struct tm date = {0};
    date.tm_year = year-1900;
    date.tm_mon  = month-1;
    date.tm_mday = day;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    int age = (difftime(current, normal) + 86400L/2) / 86400L;
    return age/365;
}

int main()
{
    input(studentinfo[0]);
    for (int i = 0; i < maxx; i++)
    {
        cout << "Name: " << studentinfo[i].fname << " " << studentinfo[i].lname << "\tBirthday: " << studentinfo[i].birthmonth << "/" 
        << studentinfo[i].birthday << "/" << studentinfo[i].birthyear << "\tAge: "
        << convert_age(studentinfo[i].birthmonth, studentinfo[i].birthday, studentinfo[i].birthyear) << 
        "\tMajor: " <<  major[i] << "\tStudent id: " << studentinfo[i].id << endl;
    }
    return 0;
}