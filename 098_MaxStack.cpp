#include<bits/stdc++.h>
using namespace std;

class MaxStack {
public:    	
    int maxVal=INT_MIN;
    stack<int> S;
    
	// Initialize MaxStack.
	MaxStack() {
		// Write your code here.
	}
	
	void specialPush(int value) {
		// Write your code here.
        S.push(value);
        maxVal=max(maxVal, value);
	}

	// Return the popped value.
	int specialPop() {
		// Write your code here.	
        if(S.empty()){
            return -1;
        }
        
        int top=S.top();
        S.pop();
        
        if(S.empty()){
            maxVal=INT_MIN;
            return top;
        }
        
        if(maxVal==top){
            stack<int> copy;
            maxVal=INT_MIN;
            
            while(!S.empty()){
                int x=S.top();
                S.pop();
                
        		maxVal=max(maxVal, x);
                copy.push(x);
            }
            
            while(!copy.empty()){
                int x=copy.top();
                copy.pop();
                
                S.push(x);
            }
        }
        
        return top;
	}

	// Return value at the top of stack.
	int specialTop() {
		// Write your code here.
        if(S.empty()){
            return -1;
        }
        
        return S.top();
	}

	// Return maximum value in stack.
	int specialMax() {
		// Write your code here.	
        if(S.empty()){
            return -1;
        }
        return maxVal;
	}
};