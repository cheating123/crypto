
Program 19: Encrypt using Knapsack cryptosystem
#include<bits/stdc++.h>
using namespace std;
int modInverse(int a, int m){
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
int encryp(int b[],char a,int n){
    int c=0;
    for(int i=0;i<n;i++)
        c+=b[n-i-1]*((int)(((a&(1<<i))!=0)?1:0));
    return c;
}
char decryp(int c,int r,int q,int w[],int n ){
    int s=modInverse(r,q);
    cout<<"The modular inverse is: "<<s<<endl;
    int c1=(c*s)%q;
    cout<<"The value of c1="<<c1<<endl;
    char x=0;
    for(int i=n-1;i>=0;i--){
        if(w[i]<=c1){
            x=x|(1<<(n-1-i));
            c1-=w[i];
        }
    }
    return x;
}
int main(){
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    int w[n],b[n],q,r;
    cout<<"Enter the superincreasing sequence"<<endl;
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"Enter the values of r and q"<<endl;
    cin>>r>>q;
    cout<<"Enter the value of the letter"<<endl;
    char a;
    cin>>a;
    cout<<"The binary representation of "<<a<<" is: ";
    for(int i=0;i<n;i++)
        cout<<(((a&(1<<i))!=0)?1:0);
    cout<<endl;
    cout<<"The array representation is: ";
    for(int i=0;i<n;i++){
        b[i]=(r*w[i])%q;
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int c=encryp(b,a,n);
    cout<<"The knapsack value is: "<<c<<endl;
    char d=decryp(c,r,q,w,n);
    cout<<"The original value is: "<<d<<endl;
    return 0;
}