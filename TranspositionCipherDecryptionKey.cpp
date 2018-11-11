Program 6:  Find the decryption key in a transposition cipher using encryption key (3,2,6,1,5,4)
#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter Plaintext: "<<endl;
	string keyword,plaintext,encrypted,decrypted;
	cin>>plaintext;
	int i,j,klen,l=plaintext.length();
	map<int,int> keyMap,decKeyMap;
	cout<<"Enter keylength: "<<endl;
	cin>>klen;
	cout<<"Enter keys: "<<endl;
	vector<int> key(klen);
	for(i=0;i<klen;i++){
		cin>>key[i];
		keyMap[key[i]]=i;
		decKeyMap[i]=key[i]-1;
	}
	vector< vector<char> > matrix;
	i=0;
	while(i<l){
		vector<char> v;
		for(j=0;j<klen && i<l;j++){
			char c=plaintext[i];
			v.push_back(c);
			i++;
		}
		matrix.push_back(v);
	}
    for(auto ii=keyMap.begin();ii!=keyMap.end();ii++){
        j=ii->second;
        for(i=0;i<matrix.size();i++)
                encrypted+=matrix[i][j];
    }
	cout<<"Encrypted text is: "<<encrypted<<endl;

	i=0;
	int l1=encrypted.length();
	int rows=l1/klen;
	char dematrix[l1/klen][klen];
	while(i<l1){
		dematrix[i%rows][i/rows]=encrypted[i];
		i++;
	}
	cout<<"Decryption Key is: ";
	for(auto ii=keyMap.begin();ii!=keyMap.end();ii++){
        j=ii->second;
        cout<<j+1<<" ";
	}
	for(i=0;i<rows;i++)
        for(auto ii=decKeyMap.begin();ii!=decKeyMap.end();ii++)
            decrypted+=dematrix[i][ii->second];

	cout<<endl<<"Decrypted text is: "<<decrypted<<endl;
	return 0;
}