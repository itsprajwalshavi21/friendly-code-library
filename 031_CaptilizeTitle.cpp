#include <bits/stdc++.h>
using namespace std;

string capitalize(string s)
{
    bool ret = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (ret == true)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = s[i] - 'a' + 'A';
            }
            ret = !ret;
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }
    return s;
}
string small(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
string capitalizeTitle(string s)
{
    string newOne;
    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        for (; s[i] != ' ' && i < s.length(); i++)
        {
            newOne.push_back(s[i]);
        }
        if (newOne.length() >= 3)
        {
            newOne = capitalize(newOne);
        }
        else
        {
            newOne = small(newOne);
        }
        ans = ans + newOne;
        ans = ans + " ";
        newOne.clear();
    }
    ans.pop_back();
    return ans;
}

int main()
{
    string title = "capiTalIze tHe titLe";
    cout << capitalize(title) << endl;
    return 0;
}