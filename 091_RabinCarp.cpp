#include<bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
	vector<int> ans;
	
	for(int i=0; i<str.length(); i++){
		bool flag=true;
		int k=i;
		for(int j=0; j<pat.length(); j++){
			if(str[k++] != pat[j]){
				flag=false;
				break;
			}
		}
		if(flag) ans.push_back(i);
	}
	
	return ans;
}
