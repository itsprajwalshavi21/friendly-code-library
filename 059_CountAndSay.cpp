#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n) 
{
	// Write your code here.	
    string result="1";
    
    while(--n){
        string curr="";
        int N=result.size();
        
        for(int i=0; i<N; i++){
            int count=1;
            
            while(i+1<N && result[i]==result[i+1]){
                count++;
                i++;
            }
            
            curr+=to_string(count)+result[i];
        }
        
        result=curr;
    }
    
    return result;
}