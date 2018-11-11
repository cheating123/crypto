
Program 12: Implement RC4 Cipher with Plaintext as 10011000 and Key as 01010000
#include<bits/stdc++.h>
#define N 256
#define M 8
using namespace std;
int s[N],t[N],k[N],p[N],n;
int conv(string s,int a[]){
	int m=0;
	for(int i=0;i<s.length();i+=M){
		n=0;
		for(int j=0;j<min(M,int(s.length()));j++){
			if(s[i+j]=='1')
				n=n|(1<<(M-j-1));
		}
		a[i/M]=n;
		m++;
	}
	return m;
}
string conv1(int a[],int n){
	string q="";
	for(int i=0;i<n;i++){
		for(int j=M-1;j>=0;j--){
			if(a[i]&(1<<j))
				q+='1';
			else
				q+='0';
		}
	}
	return q;
}
void display(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	string plain="10011000",key="01010000";
	int n,m;
	n=conv(plain,p);
	m=conv(key,k);
	for(int i=0;i<N;i++){
		s[i]=i;
		t[i]=k[i%m];
	}
	for(int i=0,j=0;i<N;i++){
		j=(j+s[i]+t[i])%N;
		swap(s[i],s[j]);
	}
	for(int r=0,i=0,j=0,k;r<n;r++){
		i=(i+1)%N;
		j=(j+s[i])%N;
		swap(s[i],s[j]);
		k=s[(s[i]+s[j])%N];
		p[r]=(p[r]^k);
	}
	cout<<"The value in decimal is: ";
	display(p,n);
	cout<<"Output is: "<<conv1(p,n)<<endl;
}