Program 7: 
(a) Encrypt ‘sendmoremoney’ with keystream (9,0,1,7,23,15,21,14,11,11,2,8,9)
(b) Find a key that decrypts ciphertext of part (a) to plaintext ‘cashnotneeded’
#include<bits/stdc++.h>
using namespace std;
string vignere(vector<int> v, string plaintext){
	string encrypted="";
	int i,l=plaintext.length();
	for(i=0;i<l;i++)
		encrypted+=char('a'+(v[i]+plaintext[i]-'a')%26);
	return encrypted;
}
vector<int> de_vignere(string encrypted, string decrypted){
	vector<int> v;
	int i,l=encrypted.length();
	for(i=0;i<l;i++)
		v.push_back((encrypted[i]-decrypted[i]+26)%26);
	return v;
}
int main(){
	string plaintext,key,encrypted,decrypted;
	cout<<"Enter Plaintext: "<<endl;
	cin>>plaintext;
	int i,len=plaintext.length();
	vector<int> ipstream(len),opstream;
	cout<<"Enter Input Stream: "<<endl;
	for(i=0;i<len;i++)
		cin>>ipstream[i];
	encrypted=vignere(ipstream,plaintext);
	cout<<"The encrypted text is: "<<encrypted<<endl;
	cout<<"Enter Decrypted Text: "<<endl;
	cin>>decrypted;
	opstream=de_vignere(encrypted,decrypted);
	cout<<"The Output Stream is: "<<endl;
	for(i=0;i<len;i++)
		cout<<opstream[i]<<" ";
	return 0;
}