
Program 17: Find primitive roots of multiplicative group
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
	int prime;
	cout<<"Enter the value of p"<<endl;
	cin>>prime;
	vector<int> generators=find_generator(prime);
	cout<<"The generators of prime "<<prime<<" are: "<<endl;
	for(auto generator:generators)
        cout<<generator<<" ";
	return 0;
}