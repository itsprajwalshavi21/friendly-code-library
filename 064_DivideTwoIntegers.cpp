#include<bits/stdc++.h>
using namespace std;

int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.
     if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        if(divisor==1){
            return dividend;
        }
        
        if(divisor==-1){
            return -1*dividend;
        }
        
        int a=abs(dividend);
        int b=abs(divisor);
        int result=0;
        
        while(a - b >= 0){
            int count=0;
            while(a - (b<<1<<count) >= 0){
                count++;
            }
            
            result += 1<<count;
            a -= b<<count;
        }
        
        return (dividend>0)==(divisor>0)?result:-result;
} 