#include<iostream>
#include<algorithm>
using namespace std;

class Fraction {
	int n, d;
    // Complete the class
	public:
	Fraction(int n, int d){
		this->n=n;
		this->d=d;
	}
	
	void add(Fraction &obj){
		n=(n*obj.d)+(obj.n*d);
		d*=obj.d;
		int gcd=__gcd(n, d);
		n/=gcd;
		d/=gcd;
	}
	
	void mult(Fraction &obj){
		d*=obj.d;
		n*=obj.n;
		int gcd=__gcd(n, d);
		n/=gcd;
		d/=gcd;
	}
	
	void print(){
		cout<<n<<"/"<<d<<endl;
	}
};

int main() {

    //Write your code here
 int num1,den1;

   cin>>num1>>den1;

   Fraction a1(num1,den1);

   int choice,t,i;

   cin>>t;  

   for(i=0;i<t;i++){

       cin>>choice;

       int num2,den2;

    cin>>num2>>den2;

       Fraction a2(num2,den2);

    if(choice==1){

           a1.add(a2);

           a1.print();

       }

       if(choice==2){

           a1.mult(a2);

           a1.print();

       }

   }

   return 0;
    return 0;
}