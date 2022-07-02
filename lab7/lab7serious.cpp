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

//compare word
/* int compare(string word[], int wordcount)
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
        occurence -= 1;
        for (int j = 0; j < wordcount; j++)
        {
            if (tempword == word[j])
            {
                occurence++;
            }
        }
    } 
    return occurence;
}  */

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
        if (j < wordcount)
        {
            strconcat += word[j] + " ";
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
    wordcount = word_count(strconcat) - 1;
    //Compare words
    //occurence = compare(word, wordcount);
    string tempcompare;
    string tempwordcompare;
    int testedcount = 0;
    int totaloccurences = 0;
    for (int i = 0; i < wordcount; i++)
    {
        tempcompare = word[i];
        transform(tempcompare.begin(), tempcompare.end(), tempcompare.begin(), ::tolower);
        word[i] = tempcompare;
        tempcompare = "";
    }
    //system("cls");
    for (int i = 0; i < wordcount; i++)
    {
        bool flag = false;
        int occuredcount = 0;
        
        for (int j = 0; j < testedcount; j++)
        {
            if(word[i] == wordoccured[j]) {
                flag = true;
            }
        }
        if(flag) continue;

        wordoccured[testedcount] = word[i];
        testedcount++;
        for (int j = 0; j < wordcount; j++)
        {
            if(word[i] == word[j]) {
                occuredcount++;
            }
        }
        cout << "" << word[i] << " occurs " << occuredcount << " times.\n";
        totaloccurences += occuredcount;
    }
/*
    for (int i = 0; i < wordcount; i++)
    {
        tempcompare = word[i];
        transform(tempcompare.begin(), tempcompare.end(), tempcompare.begin(), ::tolower);
        word[i] = tempcompare;
        tempcompare = "";
    }
    system("cls");
    //compare word by word
    for (int i = 0; i < wordcount; i++)
    {
        occurence = 0;
        tempwordcompare = word[i];
        for (int j = 0; j < wordcount; j++)
        {
            if (tempwordcompare != wordoccured[j])
            {
                wordoccured[i] = word[i];
                break;
            }
        }
        cout << wordoccured[i] << " occure: " << occurence << " time(s)" << endl;
    } */
    //Output:
    cout << "Number of words: " << wordcount << endl;
    cout << "Number of words: " << totaloccurences << endl;
    return 0;
}