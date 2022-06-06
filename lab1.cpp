//Reverse String
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string a;
    string b;
    cout << "Enter a string: ";
    getline(cin, a);
    b = a;
    //reverse input
    reverse(a.begin(), a.end());
    //cout input in reverse
    cout << "Reverse order: " << a << endl;
    //erase space in a and b in order to compare
    a.erase(remove(a.begin(), a.end(), ' ')); 
    b.erase(remove(b.begin(), b.end(), ' ')); 
    if(a == b)
    {
        cout << "The order of characters in both strings are the same";
    }
    else 
        cout << "The order of characters in both strings are not the same";
    return 0;
}