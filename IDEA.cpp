Program 27: Generate Keys of IDEA Algorithm and Implement 1 Round
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mm map<char, string>
#define m1 map<string, char>
string me(string a, mm ma){
    string a1 = "";
    for(int i = a.length()-1; i>=0; i--)
        a1 = ma[a[i]] + a1;
    return a1;
}
string xr(string a, string b){
    string re = "";
    for(int i = 0; i<a.length(); i++)
        re = re + (a[i] == b[i] ? string(1, '0') : string(1, '1'));
    return re;
}
string ad(string a, string b){
    string re = "";
    for(int i = 0; i<a.length(); i++)
        re = re + (((a[i] == '0') || (b[i] == '0')) ? string(1, '0') : string(1, '1'));
    return re;
}
string nt(string a){
    string re = "";
    for(int i = 0; i<a.length(); i++)
        re = re + (a[i] == '0' ? string(1, '1') : string(1, '0'));
    return re;
}
string ro(string a, string b){
    string re = "";
    for(int i = 0; i<a.length(); i++)
        re = re + (((a[i] == '1') || (b[i] == '1')) ? string(1, '1') : string(1, '0'));
    return re;
}
string me2(string a, m1 m2){
    string te = "", re = "";
    for(int i = 0; i<a.length(); i++){
        if(i!=0 && i% 4 == 0){
            re += m2[te];
            te = "";
        }
        te += string(1, a[i]);
    }
    re += m2[te];
    te = "";
    return re;
}
string shift(string a){
    string x="",y="";
     for(int i=25;i<a.length();i++)
        x+=a[i];
     for(int i=0;i<25;i++)
        y = y+a[i];
     x = x+y;
     return x;
}
int main(){
    string key;
    cout<<"Insert key in hexadecimal: "<<endl;
    cin>>key;
    mm ma;
    m1 m2;
    ma['0'] = "0000", ma['1'] = "0001", ma['2'] = "0010", ma['3'] = "0011";
    ma['4'] = "0100", ma['5'] = "0101", ma['6'] = "0110", ma['7'] = "0111";
    ma['8'] = "1000", ma['9'] = "1001"; ma['A'] = "1010", ma['B'] = "1011";
    ma['C'] = "1100", ma['D'] = "1101", ma['E'] = "1110", ma['F'] = "1111";
    m2["0000"] = '0', m2["0001"] = '1', m2["0010"] = '2', m2["0011"] = '3';
    m2["0100"] = '4', m2["0101"] = '5', m2["0110"] = '6', m2["0111"] = '7';
    m2["1000"] = '8', m2["1001"] = '9', m2["1010"] = 'A', m2["1011"] = 'B';
    m2["1100"] = 'C', m2["1101"] = 'D', m2["1110"] = 'E', m2["1111"] = 'F';
    string a[52],a1[52];
    string re = "",re1="";
    re = me(key,ma);
    int k=0;
    for(int i=0;i<8;i++)
        a[k++] = re.substr(16*i,16);

    for(int i=0;i<5;i++){
        re = shift(re);
        for(int i=0;i<8;i++)
            a[k++] = re.substr(16*i,16);
    }
    re=shift(re);
    re1=re.substr(0,64);
    for(int i=0;i<4;i++)
        a[k++] = re.substr(16*i,16);

    cout<<"\n52 subkeys generated are: ";
    for(int i=0;i<52;i++){
        if(i%6==0)
            cout<<endl;
        a1[i]=me2(a[i],m2);
        cout<<a1[i]<<'\t';
    }
    string p1[4],re2[4],re3[4],p,pb;
    cout<<"\nEnter the plain text: "<<endl;
    cin>>p;
    pb=me(p,ma);
    cout<<"\nEncrypted message is: "<<endl;
    for(int i=0;i<4;i++){
        p1[i] = pb.substr(16*i,16);
        re2[i] = xr(p1[i],a[i]);
        re3[i] = me2(re2[i],m2);
        cout<<re3[i];
    }
    cout<<endl;
    return 0;
}