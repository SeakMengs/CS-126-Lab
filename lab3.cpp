//Create and research push_back function
#include<iostream>  
using namespace std;  

string meng_pushback(char input, string& newstring)
{
if (input)
{
    newstring = newstring + input;
    return newstring;
}
return 0;
}

int main()  
{  
string s1 = "Hell";  
cout<< "String is :" << s1 << endl;  
//the function below is the same as s1.push_back('o');
meng_pushback('o', s1);
cout<< "Now, string is :" << s1;  
return 0;     
}