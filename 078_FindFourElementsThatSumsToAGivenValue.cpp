#include<bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
//     method-1    
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1; k<n; k++){
//                 for(int l=k+1; l<n; l++){
//                     if(arr[i]+arr[j]+arr[k]+arr[l]==target){
//                         return "Yes";
//                     }
//                 }
//             }
//         }
//     }
    
//     method-2
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-3; i++){
		if(i>0 && arr[i]==arr[i-1]) continue;
		if(arr[i]+arr[i+1]>target-(arr[i+2]+arr[i+3])) break;
		if(arr[i]+arr[n-3]<target-(arr[n-2]+arr[n-1])) continue;
		
        for(int j=i+1; j<n-2; j++){
			if(j>i+1 && arr[j]==arr[j-1]) continue;
			if(arr[i]+arr[j]>target-(arr[j+1]+arr[j+2])) break;
			if(arr[i]+arr[j]<target-(arr[n-2]+arr[n-1])) continue;
                
            int low=j+1;
            int high=n-1;
            
            while(low<high){
                int sum=arr[i]+arr[j]+arr[low]+arr[high];
                
                if(sum==target){
                    return "Yes";
                }
                
                if(sum>=target){
                    high--;
                }else{
                    low++;
                }
            }
        }
    }
    
    return "No";
}
