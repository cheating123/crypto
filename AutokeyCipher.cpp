Program 8: Encrypt ‘thehouseisbeingsoldtonight’ using Autokey cipher with key=7 and decrypt the ciphertext to obtain the plaintext again.
#include<bits/stdc++.h>
using namespace std;
string autokey(int key,string plaintext){
	string keyword="";
	int i=0,l=plaintext.length();
	while(i<l){
		if(i==0){
			keyword+=char('a'+(plaintext[i]-'a'+key)%26);
		}else{
			keyword+=char('a'+(plaintext[i]-'a'+plaintext[i-1]-'a')%26);
		}
		i++;
	}
	return keyword;
}
string de_autokey(int key,string encrypted){
	string keyword="";
	int i=0,l=encrypted.length();
	while(i<l){
		if(i==0){
			keyword+=char('a'+(encrypted[i]-'a'-key+26)%26);
		}else{
			keyword+=char('a'+(encrypted[i]-keyword[i-1]+26)%26);
		}
		i++;
	}
	return keyword;
}
int main(){
	cout<<"Enter Key: "<<endl;
	int key;
	cin>>key;
	string plaintext,encrypted;
	cout<<"Enter Plaintext: "<<endl;
	cin>>plaintext;
	encrypted=autokey(key,plaintext);
	cout<<"The encrypted text is: "<<encrypted<<endl;
	cout<<"The decrypted text is: "<<de_autokey(key,encrypted)<<endl;

	return 0;
}