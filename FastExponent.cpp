
Program 13: Implement Fast Exponent Method.
#include<bits/stdc++.h>
using namespace std;
int modexp(int x, int y, int mod){
    int res=1;
    x=x%mod;
    while(y){
        if(y&1)
            res=(res*x)%mod;
        x=(x*x)%mod;
        y=y>>1;
    }
    return res;
}
int main(){
    cout<<"Enter the value of base, exponent and modulus"<<endl;
    int x,y,mod;
    cin>>x>>y>>mod;
    int res=modexp(x,y,mod);
    cout<<"The value of modular exponentiation is: "<<res<<endl;
    return 0;
}