#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
   /* string a;
    cout << "Enter a string:";
    getline(cin, a);
    reverse(a.begin(), a.end());
    cout << "Reverse order: " << a; */
    string a;
    string b;
    char c[] = {};
    cout << "Enter a string: ";
    getline(cin, a);
    b = a;
    //strcpy(c, a.c_str());
    reverse(a.begin(), a.end());
    cout << "Reverse order: " << a << endl;
    a.erase(remove(a.begin(), a.end(), ' '), a.end()); 
    b.erase(remove(b.begin(), b.end(), ' '), b.end()); 
    if(a == b)
    {
        cout << "The order of characters in both strings are the same";
    }
    else 
        cout << "The order of characters in both strings are not the same";
    return 0;
}