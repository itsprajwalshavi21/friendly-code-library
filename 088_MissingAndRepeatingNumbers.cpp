#include<bits/stdc++.h>
using namespace std;

bool isAbsent(int i){
    return !i;
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    if(!n) return {0, 0};
    
	// Write your code here 
    int R=0, M=0;
    vector<bool> seen(n+1, false);
    seen[0]=true;
    
    for(auto num: arr){
       if(seen[num]){
           R=num;
       }
       seen[num]=true;
    }
    
//     for(int i=1; i<=n; i++){
//         if(!seen[i]){
//             M=i; 
//             break;
//         }
//     }
    
    auto it=find_if(seen.begin(), seen.end(), isAbsent);
    M=it-seen.begin();
    
    return {M, R};
}
