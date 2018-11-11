
Program 26: Implement SHA1 Algorithm
//Part1
#include<bits/stdc++.h>
using namespace std;
map<string,string> bintohex ={{"0000","0"},{"0001","1"},{"0010","2"},{"0011","3"},
{"0100","4"},{"0101","5"},{"0110","6"},{"0111","7"},
{"1000","8"},{"1001","9"},{"1010","A"},{"1011","B"},
{"1100","C"},{"1101","D"},{"1110","E"},{"1111","F"}};
map<string,string> hextobin ={{"0","0000"},{"1","0001"},{"2","0010"},{"3","0011"},
{"4","0100"},{"5","0101"},{"6","0110"},{"7","0111"},
{"8","1000"},{"9","1001"},{"A","1010"},{"B","1011"},
{"C","1100"},{"D","1101"},{"E","1110"},{"F","1111"}};
string strbin(int n){
	string s="";
	while(n){
		if(n&1)
			s = '1' + s;
		else
			s = '0' + s;
		n=n>>1;
	}
	while(s.length()<8)
		s="0"+s;
	return s;
}
string toBinary(string s){
    int length = s.length();
    int bitLength = length * 8;
    int totalLength = bitLength + (512-bitLength%512);
    string bitString = "";
    int i,j,k;
    for(i=0;i<length;i++){
    	bitString.append(strbin(int(s[i])));
    }
    return bitString;
}
string length_padding(int n){
	string pad = "";
	while(n){
		if(n&1)
			pad = '1' + pad;
		else
			pad = '0' + pad;
		n=n>>1;
	}
	int l = pad.length();
	l = 64-l;
	string zeroes = "";
	for(int i=0;i<l;i++)
		zeroes.append("0");
	pad = zeroes + pad;
	return pad;
}
string padding(string s){
    string padString;
    int length = s.length();
    string length_pad = length_padding(length*8);
    padString = toBinary(s);
    int bitLength = length * 8;
    int totalLength = bitLength + (512-bitLength%512);
    totalLength = totalLength - 64;
    if(bitLength<totalLength){
		padString.append("1");
		bitLength++;
    }
    while(bitLength<totalLength){
		padString.append("0");
		bitLength++;
    }
    padString.append(length_pad);
    return padString;
}
string toHex(string s){
	string op = "";
    int length = s.length();
    for(int i=0;i<length;i+=4){
    	string temp = s.substr(i,4);
    	op+=bintohex[temp];
    }
    return op;
}
int main(){
	cout<<"Enter Input: "<<endl;
	string s,bin,pad;
	cin>>s;
	pad=padding(s);
	cout<<"Padded Message is:"<<endl<<toHex(pad)<<endl;
	return 0;
}
//Part2
#include<bits/stdc++.h>
using namespace std;
map<string,string> bintohex ={{"0000","0"},{"0001","1"},{"0010","2"},{"0011","3"},
{"0100","4"},{"0101","5"},{"0110","6"},{"0111","7"},
{"1000","8"},{"1001","9"},{"1010","A"},{"1011","B"},
{"1100","C"},{"1101","D"},{"1110","E"},{"1111","F"}};
map<char,string> hextobin ={{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},
{'4',"0100"},{'5',"0101"},{'6',"0110"},{'7',"0111"},
{'8',"1000"},{'9',"1001"},{'A',"1010"},{'B',"1011"},
{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};
string A = "01234567";
string B = "89ABCDEF";
string C = "FEDCBA98";
string D = "76543210";
string E = "C3D2E1F0";
char XR(char c1,char c2){
	if(c1==c2)
		return '0';
	else
		return '1';
}
char AND(char c1,char c2){
	if(c1=='1' && c2=='1')
		return '1';
	else
		return '0';
}
char OR(char c1, char c2){
	if( c1=='1' || c2=='1')
		return '1';
	else
		return '0';
}
char NOT(char c){
	if(c=='1')
		return '0';
	else
		return '1';
}
string toHex(string s){
	string op = "";
    int length = s.length();
    for(int i=0;i<length;i+=4){
    	string temp = s.substr(i,4);
    	op+=bintohex[temp];
    }
    return op;
}
string toBin(string s){
	string op = "";
    int length = s.length();
    for(int i=0;i<length;i++){
    	op+=hextobin[s[i]];
    }
    return op;
}
void process1(string b, string c, string d){
	int l = b.length();
	string op = "";
	for(int i=0;i<l;i++){
		char temp1 = AND(b[i],c[i]);
		char temp2 = NOT(b[i]);
		temp2 = AND(temp2,d[i]);
		temp1 = OR(temp1,temp2);
		op=op+temp1;
	}
	cout<<toHex(op)<<endl;
}
void process2(string b, string c, string d){
	int l = b.length();
	string op = "";
	for(int i=0;i<l;i++){
        char temp1 = XR(b[i],c[i]);
        char temp2 = XR(temp1,d[i]);
		op=op+temp2;
	}
	cout<<toHex(op)<<endl;
}
void process3(string b, string c, string d){
	int l = b.length();
	string op = "";
	for(int i=0;i<l;i++){
        char temp1=AND(b[i],d[i]);
        char temp2=AND(b[i],c[i]);
        temp2=OR(temp1,temp2);
        temp1=AND(c[i],d[i]);
        temp1=OR(temp1,temp2);
		op=op+temp1;
	}
	cout<<toHex(op)<<endl;
}
void implement_process(){
	string a,b,c,d,e;
	a = toBin(A);
	b = toBin(B);
	c = toBin(C);
	d = toBin(D);
	e = toBin(E);
	cout<<"Process 1 ";
	process1(b,c,d);
	cout<<"Process 2 ";
	process2(b,c,d);
	cout<<"Process 3 ";
    process3(b,c,d);
	cout<<"Process 4 ";
	process2(b,c,d);
}
int main(){
	implement_process();
	return 0;
}
//Part3
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#define rotateleft(x,n) ((x<<n) | (x>>(32-n)))
#define rotateright(x,n) ((x>>n) | (x<<(32-n)))
void SHA1(unsigned char * str1){
	int i,j;
	unsigned long int h0,h1,h2,h3,h4,a,b,c,d,e,f,k,temp;
	h0 = 0x01234567;
	h1 = 0x89ABCDEF;
	h2 = 0xFEDCBA98;
	h3 = 0x76543210;
	h4 = 0xC3D2E1F0;
	unsigned char * str;
	str = (unsigned char *)malloc(strlen((const char *)str1)+100);
	strcpy((char *)str,(const char *)str1);
	int current_length = strlen((const char *)str);
	int original_length = current_length;
	str[current_length] = 0x80;
	str[current_length + 1] = '\0';
	char ic = str[current_length];
	current_length++;
	int ib = current_length % 64;
	if(ib<56)
	ib = 56-ib;
	else
	ib = 120 - ib;
	for(int i=0;i < ib;i++){
		str[current_length]=0x00;
		current_length++;
	}
	str[current_length + 1]='\0';
	for(i=0;i<6;i++){
		str[current_length]=0x0;
		current_length++;
	}
	str[current_length] = (original_length * 8) / 0x100 ;
	current_length++;
	str[current_length] = (original_length * 8) % 0x100;
	current_length++;
	str[current_length+i]='\0';
	int number_of_chunks = current_length/64;
	unsigned long int word[80];
	for(i=0;i<number_of_chunks;i++){
		for(int j=0;j<16;j++)
			word[j] = str[i*64 + j*4 + 0] * 0x100 + str[i*64 + j*4 + 1] ;
		for(j=16;j<80;j++)
            word[j] = rotateleft((word[j-3] ^ word[j-8] ^ word[j-14] ^ word[j-16]),1);
		a = h0;
		b = h1;
		c = h2;
		d = h3;
		e = h4;
		for(int m=0;m<80;m++){
            f = (b & c) | ((~b) & d);
            k = 0xFEDCBA98;

            temp = (rotateleft(a,5) + f + e + k + word[m]) & 0xFFFFFFFF;
            e = d;
            d = c;
            c = rotateleft(b,30);
            b = a;
            a = temp;
        }
		// second 32 bit
		for(int j=0;j<16;j++)
			word[j] = str[i*64 + j*4 + 2] * 0x100 + str[i*64 + j*4 + 3];
		for(j=16;j<80;j++)
            word[j] = rotateleft((word[j-3] ^ word[j-8] ^ word[j-14] ^ word[j-16]),1);
		for(int m=0;m<80;m++){
            f = b ^ c ^ d;
            k = 0x76543210;

            temp = (rotateleft(a,5) + f + e + k + word[m]) & 0xFFFFFFFF;
            e = d;
            d = c;
            c = rotateleft(b,30);
            b = a;
            a = temp;
        }
        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;
        h4 = h4 + e;
        }
	printf("Hash: %x %x %x %x %x",h0, h1, h2, h3, h4);
	printf("\n\n");
}
int main(){
    SHA1((unsigned char *)"hello");
    return 0;
}

