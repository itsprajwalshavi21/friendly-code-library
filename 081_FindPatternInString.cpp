#include <bits/stdc++.h>
using namespace std;

int LCS(string &X, string &Y){
    int m=X.length();
    int n=Y.length();
    
    int t[m+1][n+1]={0};
    int result=INT_MIN;
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }else{
                if(X[i-1]==Y[j-1]){
                	t[i][j]=1+t[i-1][j-1];
//                     result=max(result, t[i][j]);
                    if(t[i][j]>result){
                        result=t[i][j];
                    }
                }else{
                    t[i][j]=0;
                }
            }
        }
    }
    
    return result==INT_MIN?0:result;
}

bool findPattern(string p, string s)
{
//     Write your code here.
    int m=p.length();
    int n=s.length();
	
	if(m>n) return false;
    
//     method-1
//     return m==LCS(p, s);
	
// 	method-2
//     for(int i=0; i<n; i++){
//         bool flag=true;
        
//         for(int j=0; j<m; j++){
//             if(p[j]!=s[i+j]){
//                 flag=false;
//                 break;
//             }
//         }
        
//         if(flag){
//             return true;
//         }
//     }
    
//     return false;
    
//     method-3
	for(int i=0; i<n-m+1; i++){
		string str=s.substr(i, m);
		if(str==p){
			return true;
		}
	}
	
	return false;
}