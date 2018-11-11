
Program 18: Encrypt a string using El-Gamal Cryptosystem
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int gcd(int a,int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}
int fastexp(int x,int y, int mod){
	int res=1;
	while(y){
		if(y&1)
			res=(res*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return res;
}
vector<int> find_generator(int prime){
	int i;
	vector<int> elements, primitives;
	for(i=0;i<prime;i++){
		if(gcd(prime,i)==1)
			elements.push_back(i);
	}
	int order=elements.size();
	for(i=0;i<order;i++){
		int j;
		vector<bool> p(prime,0);
		for(j=0;j<prime;j++){
			int t=fastexp(elements[i],j,prime);
			p[t]=1;
		}
		for(j=1;j<prime;j++)
			if(p[j]==0)
				break;
		if(j==prime)
			primitives.push_back(elements[i]);
	}
	return	primitives;
}
int main(){
	srand(time(NULL));
	int i,a,beta,mod,prime,len,alpha,slen,k,y1;
	cout<<"Enter the value of p"<<endl;
	cin>>prime;
	vector<int> generators=find_generator(prime);
	len=generators.size();
	alpha=generators[rand()%len];
	a=rand()%(prime-2);
	beta=fastexp(alpha,a,prime);
	cout<<"The value of alpha is: "<<alpha<<endl;
	cout<<"The value of beta is: "<<beta<<endl;
	cout<<"The value of a is: "<<a<<endl;
	string s;
	cout<<"Enter the input string"<<endl;
	cin>>s;
	vector<int>y2;
	slen=s.length();
	k=rand()%(prime-1);
	y1=fastexp(alpha,k,prime);
	for(i=0;i<slen;i++){
		y2.push_back(s[i]*fastexp(beta,k,prime));
	}
	cout<<"Value of y1 is: "<<y1<<endl;
	cout<<"Encrypted string is: "<<endl;
	for(i=0;i<slen;i++)
		cout<<y2[i]<<" ";
	cout<<endl;
	cout<<"Decrypted string is: "<<endl;
	for(i=0;i<slen;i++){
		int temp2=y2[i];
		int temp1=y1;
		temp1=fastexp(temp1,a,prime);
		temp1=fastexp(temp1,prime-2,prime);
		temp1=(temp1*temp2)%prime;
		cout<<char(temp1);
	}
	cout<<endl;
	return 0;
}