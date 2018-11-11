

Program 16: Implement RSA Algorithm
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
int phi(int num){
    vector<int> val(num+1);
    int i,p;
    for(i=1;i<=num;i++)
        val[i]=i;
    for(p=2;p<=num;p++){
        if(val[p]==p){
            val[p]=p-1;
            for(i=2*p;i<=num;i+=p)
                    val[i]=(val[i]/p)*(p-1);
        }
    }
    return val[num];
}
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
    int p1,p2,e,d,n,totient,x,y;
    string ip; vector<int> encrypt, decrypt;
    cout<<"Enter the values of the two primes"<<endl;
    cin>>p1>>p2;
    n=p1*p2;
    totient=phi(p1);
    totient*=phi(p2);
    cout<<"Enter the value of the public key"<<endl;
    cin>>e;
    ext_eu(e,totient,x,y);
    d=(x%totient +totient)%totient;
    cout<<"The value of n is: "<<n<<endl;
    cout<<"The value of phi(n) is: "<<totient<<endl;
    cout<<"Private Key is: "<<d<<endl;
    cout<<"Enter the string to be encrypted: "<<endl;
    cin>>ip;
    cout<<"The encrypted string is: "<<endl;
    for(auto ch:ip)
        encrypt.push_back(modexp(ch,e,n));
    for(auto ch:encrypt){
        cout<<ch<<" ";
        decrypt.push_back(modexp(ch,d,n));
    }
    cout<<endl;
    cout<<"The decrypted string is: "<<endl;
    for(auto ch:decrypt)
        cout<<char(ch);
    cout<<endl;
    return 0;
}