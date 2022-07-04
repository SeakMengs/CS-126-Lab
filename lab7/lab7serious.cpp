#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

#define maxx 1000

//? remove special character, number, anything beside character
string keep_char_space(string phrase)
{
    string newphrase;
    string templine;
    string temp;
    int length = phrase.length();
    //? remove special character
    for (int i = 0; i < length; i++)
    {
        if (isalpha(phrase[i]) || phrase[i] == ' ')
        {
            newphrase += phrase[i];
        } 
    }
    //? remove last space in from the last sentence, if last sentence is a character break, else check until first condition true;
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
//? count words
int word_count (string phrase)
{
    int countword = 1;
    for (int i = 0; i < phrase.length(); i++)
    {
        if (isspace(phrase[i]))
        {
            countword++;
        }
    }
    return countword;
}

int main()
{
    fstream file, newfile;
    string phrase;
    string word[maxx];
    string wordoccured[maxx];
    string tempword;
    string temp;
    string strconcat;
    int occurence = 0;
    int wordcount = 0;
    //? open and read from countword.txt to string phrase;
    file.open("CountWord.txt", ios::in);
    if (file.is_open())
    {
        while (getline(file, phrase))
        {
            continue;
        }
        file.close();
    }
    //? remove special character, number, anything beside character
    phrase = keep_char_space(phrase);
    //? count the words
    wordcount = word_count(phrase);
    //? open and write in new file
    newfile.open("CountWordFixed.txt", ios::out);
    if (newfile.is_open())
    {
        newfile << phrase;
        newfile.close();
    }
    //? Open and get word by word from countwordfixed.txt
    newfile.open("CountWordFixed.txt", ios::in);
    if (newfile.is_open())
    {
        for (int j = 0; j < wordcount; j++)
            {
            newfile >> word[j];
            tempword = word[j];  
            for (int i = 0; i < tempword.size(); i++) 
            {
                if ((tempword[i] >= 'a' && tempword[i] <= 'z') || (tempword[i] >= 'A' && tempword[i] <= 'Z')) 
                {
                    temp = temp + tempword[i];
                }
            }
            word[j] = temp;
            if (j < wordcount)
            {
                strconcat += word[j] + " ";
            }
            temp = "";
            } 
        newfile.close();
    }
    //? Write strconcat to newfile
    newfile.open("CountWordFixed.txt", ios::out);
    if (newfile.is_open())
    {
        newfile << strconcat;
        newfile << endl;
        newfile.close();
    }
    //?count words aagain
    wordcount = word_count(strconcat) - 1;
    //?Compare words
    //occurence = compare(word, wordcount);
    string tempcompare;
    string tempwordcompare;
    int checkwordcount = 0;
    int totaloccurences = 0;
    for (int i = 0; i < wordcount; i++)
    {
        tempcompare = word[i];
        transform(tempcompare.begin(), tempcompare.end(), tempcompare.begin(), ::tolower);
        word[i] = tempcompare;
        tempcompare = "";
    }
    system("cls");
    //? loop to compare words
    for (int i = 0; i < wordcount; i++)
    {
        bool flag = false;
        int occuredcount = 0;
        //? loop to check words in array of word[i] is it = wordoccured in index j 
        //? if the check is true then make the flag true
        for (int j = 0; j < checkwordcount; j++)
        {
            if(word[i] == wordoccured[j]) {
                flag = true;
            }
        }
        //? if flag true then dont continue and the main loop will increment by 1 and check again 
        //? but if the flag false continue the below line
        if(flag) 
        continue;
        wordoccured[checkwordcount] = word[i];
        checkwordcount++;
        for (int j = 0; j < wordcount; j++)
        {
            if(word[i] == word[j]) {
                occuredcount++;
            }
        }
        //? cout the word occurs
        cout << left << setw(10) << word[i] << " occurs " << occuredcount << " times.\n";
        totaloccurences += occuredcount;
        //? write the cout into a file
        newfile.open("CountWordFixed.txt", ios::app);
        if (newfile.is_open())
        {
            newfile << endl;
            newfile << left << setw(10)<< word[i] << " occurs " << occuredcount << " times.";
            newfile.close();
        }
    }
    //? Output:
    cout << "Number of words: " << wordcount << endl;
    //cout << "Number of words: " << totaloccurences << endl;
    newfile.open("CountWordFixed.txt", ios::app);
    if (newfile.is_open())
    {
        newfile << endl << endl;
        newfile << "Number of words: " << wordcount;
        //newfile << "Number of words: " << totaloccurences;
        newfile.close();
    }
    return 0;
}