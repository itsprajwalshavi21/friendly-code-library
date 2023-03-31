#include<bits/stdc++.h>
using namespace std;

int compareVersions(string a, string b) 
{
    // Write your code here
    vector<string> num1, num2;
    
    string text1="";
    for(auto ch: a){
        if(ch=='.'){
            num1.push_back(text1);
            text1="";
        }else{
         	text1+=ch;   
        }
    }
    num1.push_back(text1);
    
    string text2="";
    for(auto ch: b){
        if(ch=='.'){
            num2.push_back(text2);
            text2="";
        }else{
         	text2+=ch;   
        }
    }
    num2.push_back(text2);
    
    int m=num1.size(), n=num2.size();
    
    if(m<n){
        for(int i=m ;i<n; i++){
            num1.push_back("0");
        }
    }else if(n<m){
        for(int i=n ;i<m; i++){
            num2.push_back("0");
        }
    }
    
    int len=max(m,n);
    
    for(int i=0; i<len; i++){
        if(num1[i] < num2[i]){
            if(num1[i].size() > num2[i].size()){
             	return 1;   
            }else{
                return -1;
            }
        }else if(num1[i] > num2[i]){
            if(num2[i].size() > num1[i].size()){
             	return -1;   
            }else{
                return 1;
            }
        }
    }
    
    return 0;
}