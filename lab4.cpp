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
//struct function
student input(student& s)
{
int n = 0;
    for (int i = 0; i < maxx; i++)
    {
    cout << "Enter first name: ";
    getline (cin, studentinfo[i].fname);
    cout << "Enter last name: ";
    getline (cin, studentinfo[i].lname);
    cout << "Enter birthmonth: ";
    cin >> studentinfo[i].birthmonth;
    cout << "Enter birthday: ";
    cin >> studentinfo[i].birthday;
    cout << "Enter birthyear: ";
    cin >> studentinfo[i].birthyear;
    cout << "Enter student id: ";
    cin >> studentinfo[i].id;
    cout << "Enter Major CS = 1, MIS = 2, BUS = 3" << endl;
    cin >> n;
    major[i]= studentinfo[i].courses[n - 1];
    cin.ignore();
    }
    return s;
}
//convert the birthday specific month/day/year to age;
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
//display info
void output(int i)
{
    cout << "Name: " << studentinfo[i].fname << " " << studentinfo[i].lname << "\tBirthday: " << studentinfo[i].birthmonth << "/" 
    << studentinfo[i].birthday << "/" << studentinfo[i].birthyear << "\tAge: "
    << convert_age(studentinfo[i].birthmonth, studentinfo[i].birthday, studentinfo[i].birthyear) << 
    "\tMajor: " <<  major[i] << "\tStudent id: " << studentinfo[i].id << endl;
}

int main()
{
    input(studentinfo[0]);
    for (int i = 0; i < maxx; i++)
    {
    output(i);
    }
    return 0;
}