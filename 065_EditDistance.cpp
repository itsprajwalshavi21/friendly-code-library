#include<bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2)
{
    //write you code here
	int m=str1.length(), n=str2.length();
	int t[m+1][n+1];
	
	for(int j=0; j<=n; j++){
		t[m][j]=n-j;
	}
	for(int i=0; i<=m; i++){
		t[i][n]=m-i;
	}
// 	t[m][n]=0;
	
	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(str1[i]==str2[j]){
				t[i][j]=t[i+1][j+1];
			}else{
				t[i][j]=1+min(t[i+1][j+1], min(t[i+1][j], t[i][j+1]));
			}
		}
	}
	
	return t[0][0];
}