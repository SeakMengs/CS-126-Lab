#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxx 1000

//remove the last special until last character is a character type
/* string remove_last_special(string phrase)
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
            for (int j = 0; j < temp.length(); j++)
            {
                templine += temp[j];
            }
            temp = templine;
            templine = "";
        }
    }
    return temp;
} */
string keep_char_space(string phrase)
{
    string newphrase;
    int length = phrase.length();
    for (int i = 0; i < length; i++)
    {
        if (isalpha(phrase[i]) || isspace(phrase[i]))
        {
            newphrase += phrase[i];
        }
    }
    return newphrase;
}

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
            for (int j = 0; j < temp.length(); j++)
            {
                templine += temp[j];
            }
            temp = templine;
            templine = "";
        }
    }
    return temp;
} 

//check how many words
int word_count (string nolastspecial)
{
    int countword = 1;
    for (int i = 0; i < nolastspecial.length(); i++)
    {
        if (isspace(nolastspecial[i]))
        {
            countword++;
        }
    }
    return countword;
}

//compare word to find number of occurrence
int compare(string word[], int wordcount)
{
    int occurence = -1;
    string temp;
    string tempword;
    //convert words into small letter to compare
    for (int i = 0; i < wordcount; i++)
    {
        temp = word[i];
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        word[i] = temp;
        temp = "";
    }
    //compare word by word
    for (int i = 0; i < wordcount; i++)
    {
        tempword = word[i];
            if (tempword == word[i])
            {
                occurence += 1;
            }
    } 
    return occurence;
}

int main()
{
    fstream file, newfile;
    string phrase;
    string removenum;
    string nolastspecial;
    string removespecial;
    string tempword;
    string temp;
    string word[maxx];
    int occurences;
    int wordcount = 0;
    //open and read from countword.txt to string phrase;
    file.open("CountWord.txt", ios::in);
    if (file.is_open())
    {
        while (getline(file, phrase))
        {
            continue;
        }
        file.close();
    }
    //remove number and character beside space and alpha
    removenum = keep_char_space(phrase);
    cout << removenum.length() << endl;
    //remove the last special until last character is a character type
    nolastspecial = remove_last_special(removenum);
    //check how many words
    wordcount = word_count(nolastspecial);

//Open and write fixed special character to newfile
newfile.open("CountWordFixed.txt", ios::out);
if (newfile.is_open())
{
    newfile << nolastspecial;
    newfile.close();
}
//Open and get word by word from countwordfixed.txt
newfile.open("CountWordFixed.txt", ios::in);
if (newfile.is_open())
{
for (int j = 0; j < wordcount; j++)
    {
    newfile >> word[j];
    tempword = word[j];  
    for (int i = 0; i < tempword.size(); i++) {
        if ((tempword[i] >= 'a' && tempword[i] <= 'z') || (tempword[i] >= 'A' && tempword[i] <= 'Z')) 
        {
            temp = temp + tempword[i];
        }
    }
    word[j] = temp;
    if (j < wordcount - 1)
    {
        removespecial += word[j] + " ";
    } else if (j == wordcount - 1)
    {
        removespecial += word[j];
    }
    temp = "";
    } 
    newfile.close();
}
newfile.open("CountWordFixed.txt", ios::out);
if (newfile.is_open())
{
    newfile << removespecial;
    newfile.close();
}
//count word again
wordcount = word_count(removespecial) - 1;
//compare word to find number of occurrence
occurences = compare(word, wordcount);
cout << "Number of words: " << wordcount << endl;
cout << "Number of occurences: " << occurences << endl;
}