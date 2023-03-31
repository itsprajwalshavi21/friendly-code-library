#include<bits/stdc++.h>
using namespace std;

int ZeroPairSum(int n, vector<int> arr){
    // Write your code here
//     method-1
	int count=0;
    
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             int sum=arr[i]+arr[j];
//             if(!sum) count++;
//         }
//     }
    
//     method-2;
//     unordered_map<int, int> seen;
    
//     for(auto num: arr){
//         if(seen[0-num]) count+=seen[0-num];
        
//         seen[num]++;
//     }
    
//     method-3
    unordered_map<int, int> pos;
    unordered_map<int, int> neg;
    
    for(auto num: arr){
        if(num>=0){
            pos[num]++;
        }else{
            neg[num]++;
        }
    }
    
    for(auto item: pos){
        if(item.first==0){
            count+=(item.second*(item.second-1)/2);
        }else{
            count+=(item.second)*(neg[-item.first]);
        }
    }
    
    return count;
}