#include<bits/stdc++.h>
using namespace std;

long long merge(long long *arr, int start, int mid, int end){
    long long count=0;
    int i=start, j=mid, k=0;
    long long copy[end-start+1];
    
    while(i<=mid-1 && j<=end){
        if(arr[i]<=arr[j]){
            copy[k++]=arr[i++];
        }else{
            copy[k++]=arr[j++];
            
            count+=(mid-i); //count elements from mid to the start or i -> mid
        }
    }
    
    while(i<=mid-1){
        copy[k++]=arr[i++];
    }
    
    while(j<=end){
        copy[k++]=arr[j++];
    }
    
    for(int s=start, p=0; s<=end; s++, p++){
        arr[s]=copy[p];
    }
    
    return count;
}

long long mergeSort(long long *arr, int start, int end){
    long long count=0;
    
    if(start<end){
        int mid=(start+end)/2;
        
        count+=mergeSort(arr, start, mid);
        count+=mergeSort(arr, mid+1, end);
        
        count+=merge(arr, start, mid+1, end);
    }
    
    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
//     method-1
//     long long count=0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i]>arr[j]) count++;
//         }
//     }
    
//     return count;
    
//     method-2
    return mergeSort(arr, 0, n-1);
}