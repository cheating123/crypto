
Program 25: Implement MD5 Algorithm
#include<bits/stdc++.h>
using namespace std;
map<char,string> m;
map<string,char> m1;
string no(string x){
    for(int i=0;i<x.length();i++){
        if(x[i]=='1')
            x[i]='0';
        else
            x[i]='1';
    }
return x;
}
string xo(string a,string b){
    string r="";
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i])
            r='0'+r;
        else
            r='1'+r;
    }
return r;
}
string oR(string a,string b){
    string r="";
    for(int i=0;i<a.length();i++){
        if((a[i]=='1')||(b[i]=='1'))
            r='1'+r;
        else
            r='0'+r;
        }
    return r;
}
string an(string a,string b){
string r="";
for(int i=0;i<a.length();i++){
    if(a[i]==b[i])
        r=a[i]+r;
    else
        r='0'+r;
    }
return r;
}
string hex(string a){
    string hex="",temp;
    for(int i=0;i<a.length();){
        temp="";
        for(int k=0;k<4;k++,i++){
            temp+=a[i];
        }
        hex+=m1[temp];
    }
return hex;
}
int main(){
    m['0']="0000";m['1']="0001";m['2']="0010";m['3']="0011";m['4']="0100";m['5']="0101";
    m['6']="0110";m['7']="0111";m['8']="1000";m['9']="1001";m['A']="1010";m['B']="1011";
    m['C']="1100";m['D']="110 1";m['E']="1110";m['F']="1111";
    m1["0000"]='0';m1["0001"]='1';m1["0010"]='2';m1["0011"]='3';m1["0100"]='4';m1["0101"]='5';
    m1["0110"]='6';m1["0111"]='7';m1["1000"]='8';m1["1001"]='9';m1["1010"]='A';m1["1011"]='B';
    m1["1100"]='C';m1["1101"]='D';m1["1110"]='E';m1["1111"]='F';
    long long k[65];
    cout<<"64 Keys are as follows:\n";
    for(int i=1;i<=64;i++){
        if(i%3==1)
            cout<<endl;
        k[i]=abs(sin(i+1))*pow(2,32);
        cout<<i<<" : "<< k[i]<<"\t";

    }
    cout<<endl;
    string a="",b="",c="",d="";
    string s1="67452301",s2="EFCDAB89",s3="98BADCFE",s4="10325476";
    for(int i=0;i<s1.length();i++){
        a=m[s1[i]]+a;
        b=m[s2[i]]+b;
        c=m[s3[i]]+c;
        d=m[s4[i]]+d;
    }
    string ans=oR(an(b,c),an(no(b),d));
    cout<<endl<<"Result of Operation A: "<<hex(ans)<<endl;
    ans=oR(an(d,b),an(no(d),c));
    cout<<"Result of Operation B: "<<hex(ans)<<endl;
    ans=xo(b,xo(c,d));
    cout<<"Result of Operation C: "<<hex(ans)<<endl;
    ans=xo(c,oR(b,no(d)));
    cout<<"Result of Operation D: "<<hex(ans)<<endl;
    return 0;
}