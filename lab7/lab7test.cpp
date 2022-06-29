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
    for (int i = 0; i < countword; i++)
    {
        myfile >> word[i];
        cout << word[i] << endl;
    }
    myfile.close();
}

    return 0;
}