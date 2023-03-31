#include<bits/stdc++.h>
using namespace std;

int calculateSquare(int num)
{
    //    Write your code here.
//     return num*num;
    if(!num) return num;
    
    num=abs(num);
    int x=num>>1;
    
    if(num&1){
//         odd
        return ((calculateSquare(x)<<2)+(x<<2)+1);
    }
//     even
    return (calculateSquare(x)<<2);
}