
Program 15: Find Modular Multiplicative Inverse using Extended Euclid Algorithm
#include<bits/stdc++.h>
using namespace std;
ext_eu(int a,int b,int &x, int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int x1,y1;
    int gcd=ext_eu(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return gcd;
}
int main(){
    cout<<"Enter the base and the modulus"<<endl;
    int a,b,x,y;
    cin>>a>>b;
    ext_eu(a,b,x,y);
    cout<<"Modular Inverse of "<<a<<" is: "<<(x%b +b)%b<<endl;
}