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
    while (getline(myfile, phrase))
    {
        continue;
    }
    myfile.close();
}
length = phrase.length(); 
for (int i = 0; i < length; i++)
{
    if ((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z') || (phrase[i] = ' ')) 
    {
    temp = temp + phrase[i];
    }
}
for (int i = 0; i < temp.length(); i++)
{
    if (isspace(temp[i]))
    {
        countword++;
    }
    if (isspace(temp[length - 1]))
    {
        countword = countword - 1;
    }
}
cout << countword;
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
    } */
    while (newfile >> tempword)
    {
        cout << tempword;
        word[testcount] = tempword;
        cout << word[testcount];
        testcount++;
    }
    myfile.close();
}

    return 0;
}