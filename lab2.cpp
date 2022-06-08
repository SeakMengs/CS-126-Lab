#include <iostream>
#include <algorithm>
using namespace std;

int meng_upper(string str)
{
    int upper = 0;
    for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
        {
			upper++;
        }
    }
    return upper;
}

int meng_lower(string str)
{
    int lower = 0;
    for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
        {
			lower++;
        }
    }
    return lower;
}

int meng_digit(string str)
{
    int digit = 0;
    for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
        {
			digit++;
        }
    }
    return digit;
}

int meng_special(string str)
{
    int upper = 0, lower = 0, number = 0, special = 0;
    for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		else if (str[i]>= '0' && str[i]<= '9')
			number++;
		else
			special++;
	}
    return special;
}

/*string meng_reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
} */

/*string meng_reverse(string str)
{
    string newstr;
    for (int n = str.length()-1; n >= 0; n--)
    {
    newstr.push_back(str[n]);
    }
    return newstr;
} */

string meng_reverse(string str)
{
    int len = str.length();
  int n = len-1;
  for (int i=0;i<(len/2);i++)
  {
    swap(str[i],str[n]);
    n = n-1;
  }
  return str;
} 

int main()
{
    int upper = 0, lower = 0, number = 0, special = 0;
    string reverse;
	string str;
    cout << "Enter a string: ";
    getline(cin, str);
	upper = meng_upper(str);
    lower = meng_lower(str);
    number = meng_digit(str);
    special = meng_special(str);
    reverse = meng_reverse(str);
    cout << "Uppercase : " << upper << endl;
	cout << "Lowercase : " << lower << endl;
	cout << "Digits : " << number << endl;
	cout << "Others : " << special << endl;
    cout << "The reverse of the string is : " << reverse << endl;
	return 0;
}
