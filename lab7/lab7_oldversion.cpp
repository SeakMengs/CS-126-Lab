#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define maxx 1000

string removespecial(string phrase)
{
    string temp;
    for (int i = 0; i < phrase.size(); i++) 
    {
        if ((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z') || (phrase[i] = ' ')) 
        {
            temp = temp + phrase[i];
        } else if (!isalpha(phrase[phrase.length()-1]))
        {
            break;
        }
    }
    phrase = temp;
    temp = "";
    return phrase;
}

string isword(string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (isalpha(word[i]))
        {
            return word;
        }
    }
    return 0;
}
bool iswordcheck(string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (isalpha(word[i]))
        {
            return true;
        }
    }
    return 0;
}
int main()
{
string word[maxx];
string temp = "";
string tempword;
string phrase;
int sameword = 0;
int countword = 1;
int wordcount = 0;
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
cout << removespecial(phrase) << endl;
for (int i = 0; i < phrase.length(); i++)
{
    if (isspace(phrase[i]))
    {
        countword++;
    }
    /*if (isspace(phrase[phrase.length() - 1]))
    {
        countword = countword - 1;
    } */
    /* if (isalpha(phrase[phrase.length()-1]))
    {
        continue;
    } else 
    {
        countword = countword - 1;
    } */
}
cout << countword;
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
}
    myfile.close();
}
cout << "Words: ";
bool iswordtrue = true;
for (int i = 0; i < countword; i++)
{
    if (iswordcheck(word[i]))
    {
        wordcount++;
    }
    cout << isword(word[i]) ;
}
cout << endl;
cout << "Words: " << wordcount << endl;
    return 0;
}