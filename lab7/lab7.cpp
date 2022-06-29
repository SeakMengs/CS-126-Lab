#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define maxx 1000

int main()
{
string word[maxx];
string temp = "";
string tempword;
string phrase;
int countword = 1;
fstream myfile, newfile;
myfile.open("CountWord.txt", ios::in);
if (myfile.is_open())
{
    while (getline(myfile, phrase))
    {
        continue;
    }
    myfile.close();
}
for (int i = 0; i < phrase.length(); i++)
{
    if (isspace(phrase[i]))
    {
        countword++;
    }
    if (isspace(phrase[phrase.length() - 1]))
    {
        countword = countword - 1;
    }
}
cout << countword << endl;
myfile.open("CountWord.txt", ios::in);
if (myfile.is_open())
{
for (int j = 0; j < countword; j++)
{
    myfile >> word[j];
    tempword = word[j];
    for (int i = 0; i < tempword.size(); i++) {
        if ((tempword[i] >= 'a' && tempword[i] <= 'z') || (tempword[i] >= 'A' && tempword[i] <= 'Z')) 
        {
            temp = temp + tempword[i];
        }
    }
    word[j] = temp;
    temp = "";
    cout << "Output String: " << word[j] << endl;
}
    myfile.close();
}

    return 0;
}