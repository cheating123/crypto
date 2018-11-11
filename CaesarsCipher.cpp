Program 1: Write a program to implement Caesar’s Cipher
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter Input String"<<endl;
	string text;
	cin>>text;
	cout<<"Enter key"<<endl;
	int key;
	cin>>key;
	key=key%26;
	string encrypted=text;
	int i,l=text.length();
	for(i=0;i<l;i++){
		if(text[i]>='a' && text[i]<='z')
			encrypted[i]=((text[i]-'a'+key+26)%26)+'a';
		else if(text[i]>='A' && text[i]<='Z')
			encrypted[i]=((text[i]-'A'+key+26)%26)+'A';}
	cout<<"The encrypted string is: "<<encrypted<<endl;
	string decrypted=encrypted;
	for(i=0;i<l;i++){
		if(encrypted[i]>='a' && encrypted[i]<='z')
			decrypted[i]=((encrypted[i]-'a'-key+26)%26)+'a';
		else if(encrypted[i]>='A' && encrypted[i]<='Z')
			decrypted[i]=((encrypted[i]-'A'-key+26)%26)+'A';
	}
	cout<<"The decrypted string is: "<<decrypted<<endl;
	return 0;
}
