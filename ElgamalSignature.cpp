
22. Implement Elgamal Digital Signature.

#include<bits/stdc++.h>
using namespace std;
int modInverse(int a, int m){
	a = a%m;
	for (int x=1; x<m; x++)
		if ((a*x) % m == 1)
			return x;
}
int exp(int b,int e,int m){
	int r=1;
	while(e>0){
		if(e&1)
			r=(r*b)%m;
		e/=2;
		b=(b*b)%m;
	}
	return r;
}
int main(){
	int m,p,e1,d,r;
	cout<<"** Elgamal Digital Signature **\nEnter m, p, e1, d ,r: ";
	cin>>m>>p>>e1>>d>>r;
	int e2=exp(e1,d,p);
	int s1=exp(e1,r,p);
	int rr=modInverse(r,p-1);
	int s2=((m-d*s1)*rr)%(p-1);
	while(s2<0)
		s2+=p-1;
	s2=s2%(p-1);
	int v2=(exp(e2,s1,p)*exp(s1,s2,p))%p;
	int v1=exp(e1,m,p);
	cout<<"\nv1 = "<<v1<<endl<<"v2 = "<<v2<<endl;
	if(v1==v2)
		cout<<"Accept"<<endl;
	else
		cout<<"Reject"<<endl;
	return 0;
}