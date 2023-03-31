#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &positions, int n, int dist, int c){
    int ninjasPlaced=1, recentPlacedAt=0;
    
    for(int i=1; i<n; i++){
        if(positions[i]-positions[recentPlacedAt] >= dist){
            recentPlacedAt=i;
            ninjasPlaced++;
        }
    }
    
    if(ninjasPlaced>=c){
        return true;
    }
    
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    
    int low=0, high=positions[n-1]-positions[0];
    int ans=0;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(canPlace(positions, n, mid, c)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
    return ans;
}