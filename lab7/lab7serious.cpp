#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxx 1000

//remove special character, number, anything beside character
string keep_char_space(string phrase)
{
    string newphrase;
    string templine;
    string temp;
    int length = phrase.length();
    //remove special character
    for (int i = 0; i < length; i++)
    {
        if (isalpha(phrase[i]) || phrase[i] == ' ')
        {
            newphrase += phrase[i];
        } 
    }
    //remove last space in from the last sentence, if last sentence is a character break, else check until first condition true;
    length = newphrase.length();
    temp = newphrase;
    for (int i = temp.length(); i > 0; i--)
    {
        if (isalpha(temp[i]))
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
//count words
int word_count (string phrase)
{
    int countword = 0;
    for (int i = 0; i < phrase.length(); i++)
    {
        if (isspace(phrase[i]))
        {
            countword++;
        }
    }
    return countword;
}

//compare word
int compare(string word[], int wordcount)
{
    int occurence = 0;
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
    string word[maxx];
    string tempword;
    string temp;
    string strconcat;
    int occurence = 0;
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
    //remove special character, number, anything beside character
    phrase = keep_char_space(phrase);
    //count the words
    wordcount = word_count(phrase);
    //open and write in new file
    newfile.open("CountWordFixed.txt", ios::out);
    if (newfile.is_open())
    {
        newfile << phrase;
        newfile.close();
    }
    //Open and get word by word from countwordfixed.txt
    /*newfile.open("CountWordFixed.txt", ios::in);
    if (newfile.is_open())
    {
        for (int j = 0; j < wordcount; j++)
        {
            newfile >> word[j];
        }
    } */
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
            strconcat += word[j] + " ";
        } else if (j == wordcount - 1)
        {
            strconcat += word[j];
        }
        temp = "";
        } 
        newfile.close();
    }
    //Write strconcat to newfile
    newfile.open("CountWordFixed.txt", ios::out);
    if (newfile.is_open())
    {
        newfile << strconcat;
        newfile.close();
    }
    //count words aagain
    wordcount = word_count(strconcat);
    //Compare words
    occurence = compare(word, wordcount);
    //Output:
    system("cls");
    cout << "Number of words: " << wordcount << endl;
    cout << "Number of occurences: " << occurence << endl;
    return 0;
}