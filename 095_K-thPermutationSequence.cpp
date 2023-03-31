#include<bits/stdc++.h>
using namespace std;

int getNFact(int n){
	int f=1;
	for(int i=2; i<=n; i++) f*=i;
	return f;
}

string kthPermutation(int n, int k) {
	// Write your code here.
	string ans="";
	
// 	method-1
// 	vector<int> nums;
// 	for(int i=1; i<=n; i++) nums.push_back(i);
	
// 	for(int i=1; i<k; i++){
// 		next_permutation(nums.begin(), nums.end());
// 	}
	
// 	for(auto num: nums) ans+=to_string(num);
	
// 	method-2
// 	vector<int> nums;
// 	for(int i=1; i<=n; i++) nums.push_back(i);
	 
// 	int fact=n==1||n==0 ? 1 : getNFact(n-1);
	
// 	swap(nums[0], nums[(k-1)/fact]);
// 	sort(nums.begin()+1, nums.end());
	
// 	for(int i=1; i<=(k-1)%fact; i++){
// 		next_permutation(nums.begin()+1, nums.end());
// 	}
	
// 	for(auto num: nums) ans+=to_string(num);
	
// 	method-3
	int fact=1;
	vector<int> nums;
	for(int i=1; i<n; i++){
		nums.push_back(i);
		fact*=i;
	}
	nums.push_back(n);
	
	k-=1;
	
	while(true){
		ans+=to_string(nums[k/fact]);
		nums.erase(nums.begin()+k/fact);
		
		if(!nums.size()) break;
		
		k%=fact;
		fact/=nums.size();
	}
	
	return ans;
}
