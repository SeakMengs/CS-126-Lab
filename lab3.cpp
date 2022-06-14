//Create and research push_back function
#include<iostream>  
using namespace std;  

void meng_pushback(char input, string& newstring)
{
if (input)
{
    newstring = newstring + input;
}
}

int main()  
{  
string s1 = "Hell";  
string s2 = "Hello";
cout<< "String is :" << s1 << endl;  
//the function below is the same as s1.push_back('o');
meng_pushback('o', s1);
cout<< "Now, string is :" << s1 << endl;

//test with array using real function
s1 = "Hell"; 
s1.push_back(s2[4]);
cout << "Original function output is: " << s1 << endl;
//Make string s1 = "Hell" again in other to compare
s1 = "Hell";  
//test with array using my functin
meng_pushback('o', s1);
cout << "My function output is: " << s1 << endl;
return 0;     
}