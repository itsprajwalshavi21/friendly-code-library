#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int> result;
    int n=arr.size();
    
//     for(int i=0; i<=n-k; i++){
//         method-1
//         set<int> nums(arr.begin()+i, arr.begin()+i+k);
        
//         method-2
//         vector<int> nums;
//         for(int j=i; j<i+k; j++){
//             if(find(nums.begin(), nums.end(), arr[j]) == nums.end()){
//                 nums.push_back(arr[j]);
//             }
//         }
//         result.push_back(nums.size());
//     }
    
    unordered_map<int, int> freq;
    
    for(int i=0; i<k; i++) freq[arr[i]]++;
    
    result.push_back(freq.size());
    
//         method-3;
        for(int i=k; i<n; i++){
            if(freq[arr[i-k]] == 1){
                freq.erase(arr[i-k]);
            }else{
                freq[arr[i-k]]--;
            }
            
            freq[arr[i]]++;
        	result.push_back(freq.size());
        }
    
    return result;
}
