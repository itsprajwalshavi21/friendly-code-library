#include<bits/stdc++.h>
using namespace std;    

bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    
    int m=str1.length(), n=str2.length();
    
    if(m!=n) return false;
    
    for(int i=0; i<m; i++){
        count1[str1[i]-'a']++;
        count2[str2[i]-'a']++;
    }
    
    return count1==count2;
}