#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define maxx 1000

int main()
{
string word[maxx];
string temp;
string phrase;
string tempword;
int countword = 1;
int length = 0;
fstream myfile, newfile;
//cout << "Enter the phrase: ";
//getline(cin, word);
myfile.open("CountWord.txt", ios::in);
if (myfile.is_open())
{
    while (getline(myfile, temp))
    {
        continue;
    }
    myfile.close();
}
for (int i = 0; i < temp.length(); i++)
{
    if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z') || (temp[i] = ' ')) 
    {
    phrase = phrase + temp[i];
    }
}
for (int i = 0; i < phrase.length(); i++)
{
    if (isspace(phrase[i]))
    {
        countword++;
    }
    if (isspace(phrase[length - 1]))
    {
        countword = countword - 1;
    }
}
myfile.open("CountWord.txt", ios::in);
if (myfile.is_open())
{
    for (int i = 0; i < countword; i++)
    {
        myfile >> word[i];
        
    }
    myfile.close();
}
/*
int testcount = 0;
newfile.open("CountWordFixed.txt", ios::out);
if (newfile.is_open())
{
    newfile << temp;
    myfile.close();
}
newfile.open("CountWordFixed.txt", ios::in);
if (newfile.is_open())
{
    /*for (int i = 0; i < countword; i++)
    {
        newfile >> word[i];
        cout << word[i] << endl;
    } 
    while (newfile >> tempword)
    {
        cout << tempword;
        word[testcount] = tempword;
        cout << word[testcount];
        testcount++;
    }
    myfile.close();
} */
    return 0;
}