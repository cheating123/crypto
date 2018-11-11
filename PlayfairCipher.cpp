Program 4: Write a program to implement Playfair Cipher
#include<bits/stdc++.h>
using namespace std;
map< char,pair<int,int> > hashmap;
char alphabets[5][5];
string inputprocess(string key){
	int i,l=key.length();
	string output="";
	for(i=0;i<l;i+=2)
		if(key[i]==key[i+1] & i+1<l){
			output+=key[i];
			output+='X';
			i--;
		}else if(i+1<l){
			output+=key[i];
			output+=key[i+1];
		}else
			output+=key[i];
	l=output.length();
	if(l%2)
		output+='X';
	return output;
}
void buildmatrix(string key){
	int A[26]={0};
	int i=0,j=0,l=key.length();
	for(int k=0;k<l;k++){
		i=k/5;
		j=k%5;
		hashmap[key[k]]={i,j};
		alphabets[i][j]=key[k];
		A[key[k]-'A']=1;
	}
	for(int letter=0;letter<26;letter++){
        if(A[letter])
            continue;
        else if((letter+'A')=='J')
            A[letter]=1;
        else{
            if(j==4){
                j=0;
                i++;
            }else
                j++;
            hashmap[char(letter+'A')]={i,j};
            alphabets[i][j]=char(letter+'A');
        }
    }
}
string modify(string plaintext,int encrypt){
    string output="";
    int t,l=plaintext.length();
    if(encrypt)
        t=1;
    else
        t=-1;
    for(int i=0;i<l;i+=2){
        char a=plaintext[i];
        char b=plaintext[i+1];
        if(a=='J')
            a='I';
        if(b=='J')
            b='I';
        pair<int,int> loc_a=hashmap[a];
        pair<int,int> loc_b=hashmap[b];
        if(loc_a.first==loc_b.first){
            output+=alphabets[loc_a.first][(loc_a.second+t+5)%5];
            output+=alphabets[loc_b.first][(loc_b.second+t+5)%5];
        }else if(loc_a.second==loc_b.second){
            output+=alphabets[(loc_a.first+t+5)%5][loc_a.second];
            output+=alphabets[(loc_b.first+t+5)%5][loc_b.second];
        }else{
            output+=alphabets[loc_a.first][loc_b.second];
            output+=alphabets[loc_b.first][loc_a.second];
        }
    }
    return output;
}
int main(){
	string plain;
	cout<<"Enter PlainText"<<endl;
	cin>>plain;
	plain=inputprocess(plain);
	string key;
	cout<<"Enter Key"<<endl;
	cin>>key;
	cout<<"The Matrix is:"<<endl;
    buildmatrix(key);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<alphabets[i][j]<<" ";
        }
        cout<<endl;
    }
    string output=modify(plain,1);
    cout<<"Encrypted String is: "<<output<<endl;
    plain=modify(output,0);
    int l=plain.length();
    cout<<"Decrypted String is: ";
    for(int i=0;i<l;i++)
        if(plain[i]=='I')
            cout<<"(I|J)";
        else
            cout<<plain[i];
}