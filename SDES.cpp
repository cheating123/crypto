
Program 9: Write a to encrypt and decrypt given test data using S-DES
        Plain Text: 1010010		Key: 0111111101
#include<bits/stdc++.h>
using namespace std;
void p(vector<int> v){
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
}
vector<int> permute(vector<int> v,int p[],int l){
	vector<int> ans(l);
	for(int i=0;i<l;i++)
	ans[i] = v[p[i]-1];
	return ans;
}
vector<int> cycle_shift(vector<int> v,int n){
	int l = v.size();
	vector<int> v1(v.begin(),v.begin()+l/2);
	vector<int> v2(v.begin()+l/2,v.end());
	rotate(v1.begin(),v1.begin()+n,v1.end());
	rotate(v2.begin(),v2.begin()+n,v2.end());
	v1.insert(v1.end(),v2.begin(),v2.end());
	return v1;
}
void generate_keys(vector<int> key,vector<int> &k1,vector<int> &k2){
	int a10[] = {3,5,2,7,4,10,1,9,8,6};
	int a8[] = {6,3,7,4,8,5,10,9};
	key = permute(key,a10,10);
	k1 = cycle_shift(key,1);
	k2 = cycle_shift(k1,2);
	k1 = permute(k1,a8,8);
	k2 = permute(k2,a8,8);
}
void fk(vector<int> &ptext, vector<int> k){
	int s1[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
	int s2[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
	int ep[] = {4,1,2,3,2,3,4,1};
	int p4[] = {2,4,3,1};
	vector<int> L(ptext.begin(),ptext.begin()+4);
	vector<int> R(ptext.begin()+4,ptext.end());
	vector<int> v = permute(R,ep,8);
	for(int i=0;i<8;i++)
		v[i] = v[i] ^ k[i];
	vector<int> v1(v.begin(),v.begin()+4);
	vector<int> v2(v.begin()+4,v.end());
	int r1 = v1[0]*2+v1[3], c1 = v1[1]*2+v1[2];
	int r2 = v2[0]*2+v2[3], c2 = v2[1]*2+v2[2];
	ptext.clear();
	ptext.push_back(s1[r1][c1]/2);
	ptext.push_back(s1[r1][c1]%2);
	ptext.push_back(s2[r2][c2]/2);
	ptext.push_back(s2[r2][c2]%2);
	ptext = permute(ptext,p4,4);
	for(int i=0;i<4;i++)
	ptext[i] = ptext[i] ^ L[i];
	ptext.insert(ptext.end(),R.begin(),R.end());
}
int main(){
	vector<int> ptext(8),key(10),k1(8),k2(8);
	int ip[] = {2,6,3,1,4,8,5,7};
	int ipi[] = {4,1,3,5,7,2,8,6};
	cout<<"Enter the plain text : ";
	for(int i=0;i<8;i++)
	cin>>ptext[i];
	cout<<"Enter the key : ";
	for(int i=0;i<10;i++)
	cin>>key[i];
	generate_keys(key,k1,k2);
	cout<<"Key 1 : ";
	p(k1);
	cout<<"Key 2 : ";
	p(k2);
	//Encryption
       ptext = permute(ptext,ip,8);
	fk(ptext,k1);
	rotate(ptext.begin(),ptext.begin()+4,ptext.end());
	fk(ptext,k2);
	ptext = permute(ptext,ipi,8);
	cout<<"Cipher text : ";
	p(ptext);
	//Decryption
	ptext = permute(ptext,ip,8);
	fk(ptext,k2);
	rotate(ptext.begin(),ptext.begin()+4,ptext.end());
	fk(ptext,k1);
	ptext = permute(ptext,ipi,8);
	cout<<"Decrypted text : ";
	p(ptext);
	return 0;
}