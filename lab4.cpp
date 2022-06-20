//Struct (build student input and display student information)
#include <iostream>
#include <iomanip>
using namespace std;

#define maxx 1
string major[3];
struct student
{
    string fname;
    string lname;
    string name;
    string id;
    int studentgrade;
    int birthday;
    int birthmonth;
    int birthyear;
    string day;
    string month;
    string year;
    string cakeday;
    string courses[3] = {"CS", "MIS", "BUS"};
} studentinfo[maxx];
//struct function
void input()
{
int n = 0;
    for (int i = 0; i < maxx; i++)
    {
    cout << "Enter first name: ";
    getline (cin, studentinfo[i].fname);
    cout << "Enter last name: ";
    getline (cin, studentinfo[i].lname);
    studentinfo[i].name = studentinfo[i].fname + " " + studentinfo[i].lname;
    cout << "Enter birthmonth: ";
    cin >> studentinfo[i].birthmonth;
    studentinfo[i].month = to_string(studentinfo[i].birthmonth);
    cout << "Enter birthday: ";
    cin >> studentinfo[i].birthday;
    studentinfo[i].day =  to_string(studentinfo[i].birthday);
    cout << "Enter birthyear: ";
    cin >> studentinfo[i].birthyear;
    studentinfo[i].year = to_string(studentinfo[i].birthyear);
    studentinfo[i].cakeday = studentinfo[i].month + "/" + studentinfo[i].day + "/" + studentinfo[i].year;
    cout << "Enter student id: ";
    cin >> studentinfo[i].id;
    cout << "Enter Major [1]CS [2]MIS [3]BUS" << endl;
    cin >> n;
    major[i]= studentinfo[i].courses[n - 1];
    cin.ignore();
    }
}

//Credit to https://thecleverprogrammer.com/2021/08/12/age-calculator-using-c/
//convert the birthday specific month/day/year to age;
/*int convert_age(int month, int day, int year)
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
} */
int convert_age(int month, int day, int year)
{
    int cage = 2022 - year;
    int cmonth = 12 - month;
    int cday = 30 - day;
    int agebyday = (cage * 365) + (12*30) + cday;
    int age = agebyday / 365;
    return age - 2;
}
//display info
void output(int i)
{
    cout << "|" << left << setw(5) << i << "|"
         << left << setw(20) << studentinfo[i].name << "|"
         << left << setw(15) << studentinfo[i].cakeday << "|"
         << left << setw(7) << convert_age(studentinfo[i].birthmonth, studentinfo[i].birthday, studentinfo[i].birthyear) << "|"
         << left << setw(15) << studentinfo[i].id << "|"
         << left << setw(5) << major[i]  << "|" << endl;
    cout << setfill('-') << setw(74) << "" << endl;
    cout << setfill(' ');
}

int main()
{
    input();
    /*
      setw() is used to change the width of the output field.
      For example, if we are assigning the width as 4 and printing the word ‘one’,
      which is a three-letter word, the output will add one blank space to the result to make it equal to the width.
      setfill() takes one character as the argument and uses it as the fill character.
      Output: "**one" 
      By default, the printing word is added to the right side but we can also use std::left to print it on left.
      Output: "one**" 
      Credit: https://www.codevscolor.com/c-plus-plus-print-data-table
    */
    cout << setfill('-') << setw(74) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(5) << "|N.O" << left << setw(20) << " |NAME" << left << setw(15) << "  |Birthday" << left << setw(7) << "   |AGE" << left << setw(15) << "    |STUDENT ID" << left << setw(5) << "     |MAJOR|"<< endl;
    cout << setfill('-') << setw(74) << "" << endl;
    cout << setfill(' ');
    for (int i = 0; i < maxx; i++)
    {
    output(i);
    }

    return 0;
}