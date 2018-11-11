Program 5: Write a program using Vignere Cipher with keyword ‘health’ to encipher the message ‘lifeisfullofsurprises’.
#include<bits/stdc++.h>
using namespace std;
string process_key(string key,int p_len){
	string keyword="";
	int i=0,j=0,key_l=key.length();
	while(i<p_len){
		if(j==key_l)
			j=0;
		keyword+=key[j];
		i++,j++;
	}
	return keyword;
}
string vignere(string key, string plaintext){
	string encrypted="";
	int i,l=plaintext.length();
	for(i=0;i<l;i++)
		encrypted+=char('a'+((key[i]-'a')%26+(plaintext[i]-'a')%26)%26);
	return encrypted;
}
string de_vignere(string key, string enctext){
	string encrypted="";
	int i,l=enctext.length();
	for(i=0;i<l;i++)
		encrypted+=char('a'+(enctext[i]-key[i]+26)%26);
	return encrypted;
}
int main(){
	cout<<"Enter Keyword: "<<endl;
	string keyword,plaintext,key,encrypted;
	cin>>keyword;
	cout<<"Enter Plaintext: "<<endl;
	cin>>plaintext;
	int plain_len=plaintext.length();
	key=process_key(keyword,plain_len);
	encrypted=vignere(key,plaintext);
	cout<<"The encrypted text is: "<<encrypted<<endl;
	cout<<"The decrypted text is: "<<de_vignere(key,encrypted)<<endl;

	return 0;
}