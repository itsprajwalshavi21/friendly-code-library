/*
Date             : 09/02/2023
!Difficulty      : Average
Interest         : High
!Needs revision  : YES
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubSeq(string s1, string s2)
{
    int len1, len2;
    len1 = s1.length();
    len2 = s2.length();
    int LCS[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        LCS[i][0] = 0;
    }
    for (int i = 0; i <= len2; i++)
    {
        LCS[0][i] = 0;
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    return LCS[len1][len2];
}

int main()
{
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << "Longest common subsequence: " << LongestSubSeq(s1, s2) << endl;
    return 0;
}