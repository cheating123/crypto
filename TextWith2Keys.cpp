Program 3: Write a program to find an enciphered text with two deciphering keys.
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter Input String"<<endl;
	string text;
	cin>>text;
	int l=text.length();
	int i,key;
	for(key=1;key<=25;key++){
		cout<<"Key is :"<<key;
		string encrypted=text;
		for(i=0;i<l;i++){
			if(text[i]>='a' && text[i]<='z')
				encrypted[i]=((text[i]-'a'+key+26)%26)+'a';
			else if(text[i]>='A' && text[i]<='Z')
				encrypted[i]=((text[i]-'A'+key+26)%26)+'A';
		}
		cout<<" "<<encrypted<<endl;
	}
	return 0;
}