#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string str;
    string newStr;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            str.push_back(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            str.push_back(s[i] - 'A' + 'a');
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            str.push_back(s[i]);
        }
    }
    int k = str.length() - 1;
    for (int i = k; i >= 0; i--)
    {
        newStr.push_back(str[i]);
    }
    if (str == newStr)
    {
        return 1;
    }
    return 0;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    //amanaplanacanalpanama
    cout << isPalindrome(s);
    return 0;
}