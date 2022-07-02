#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define maxx 1000

string remove_last_special(string phrase)
{
    string temp = phrase;
    string templine= "";
    int length = phrase.length();
    for (int i = length; i > 0; i--)
    {
        if (isalpha(phrase[i]))
        {
            break;
        } else
        {
            for (int j = 0; j < temp.length() - 1; j++)
            {
                templine += temp[j];
            }
            temp = templine;
            templine = "";
        }
    }
    return temp;
}

int main()
{
string word[maxx];
string temp = "";
string tempword;
string phrase;
int sameword = 0;
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
    /* if (isspace(phrase[phrase.length() - 1]))
    {
        countword = countword - 1;
    } */
}
myfile.open("CountWord.txt", ios::in);
if (myfile.is_open())
{
for (int j = 0; j < countword; j++)
{
    myfile >> word[j];
    tempword = word[j];
    cout << tempword.size();
    for (int i = 0; i < tempword.size(); i++) {
        if ((tempword[i] >= 'a' && tempword[i] <= 'z') || (tempword[i] >= 'A' && tempword[i] <= 'Z')) 
        {
            temp = temp + tempword[i];
        }
    }
    word[j] = temp;
    temp = "";
    cout << "Words: " << word[j] << ", "<< endl;
}
    myfile.close();
}
cout << "Words: " << countword << endl;
    return 0;
}