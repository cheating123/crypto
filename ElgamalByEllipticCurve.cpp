
24. ELGAMAL SIMULATED BY ELLIPTIC CURVE CRYPTOGRAPHY.

#include<bits/stdc++.h>
using namespace std;
struct coord
{	int x;	int y;   };
int inverse(int a, int p)
{
	for(int i = 1; i < p; i += 1)
		if((a * i) % p == 1)
			return i;
}
coord generate(int a, int b, int p){
	vector<int> y_2;
	vector<int> x;
	for(int i = 0; i < p; i += 1)
	{
		y_2.push_back((i * i * i + a * i + b) % p);
		x.push_back(i);
	}
	for(int i = 0; i < p; i += 1)
	{			
		for(int j = 0; j < x.size(); j += 1)
		{
			if(y_2[j] == ((i * i) % p))
			{
				coord res;
				res.x = x[j];
				res.y = i;
				return res;
}	}	}	}
int find_lambda(struct coord a, struct coord b, int p)
{
	int lambda;
	if((a.x == b.x) && (a.y == b.y))
	{
		int nr = (p + 3 * a.x * a.x + 1);int dr = (p + 2 * a.y);
		lambda = (p + nr * inverse(dr, p)) % p;
	}
	else
	{
		int nr = (b.y - a.y);		int dr = (b.x - a.x);
		lambda = (p + nr * inverse(dr, p)) % p;
	}
	return lambda;
}
struct coord addn(struct coord a, struct coord b, int p){
	struct coord res;	int lambda = find_lambda(a, b, p);	
	res.x = (p + lambda * lambda - a.x - b.x) % p;
	res.y = (p + lambda * (a.x - res.x) - a.y) % p;
	return res;
}
struct coord mult(int d, struct coord e1, int p){
	coord e2;	int v = d;
	struct coord temp;
	temp.x = e1.x;	temp.y = e1.y;
	for(int i = 0; i < v; i += 1)
	{
		if(temp.x < 0)
			temp.x += p;
		if(temp.y < 0)
			temp.y += p;
		if(temp.x == e1.x && (temp.y != e1.y))
		{
			temp = e1;
			i += 2;
		}
		else	temp = addn(temp, e1, p);
	}
	e2.x = ((temp.x >= 0) ? (temp.x) : (p + temp.x));
	e2.y = ((temp.y >= 0) ? (temp.y) : (p + temp.y));
	return e2;
}
int main(){
	int p, a, b, d;	cout<<"** ELLPTIC CURVE SIMULATING ELGAMAL **\nEnter p, a, b, d: ";
	cin >> p >> a >> b >> d;
	struct coord plain;
	struct coord e1 = generate(a, b, p);	struct coord e2 = mult(d, e1, p);
	cout << "E1 " << e1.x << " " << e1.y << endl;
	cout << "E2 " << e2.x << " " << e2.y << endl;
	int r = 27;
	struct coord c1 = mult(r, e1, p);
	cout << "C1 " << c1.x << " " << c1.y << endl;
	cout<<"\n Enter the number of test case: ";	int t;	cin>>t;
	for(int i=0;i<t;i++){
	cout<<"\nENter Coordinates: ";
	cin >> plain.x >> plain.y;
	struct coord c2 = addn(plain, mult(r, e2, p), p);
	cout << "C2 " << c2.x << " " << c2.y << endl;
	struct coord decr = addn(c2, mult(-1, mult(d, c1, p), p), p);
	cout << "Decrypted " << ((decr.x >= 0) ? (decr.x) : (p + decr.x)) << " " << ((decr.y >= 0) ? (decr.y) : (p + decr.y)) << endl;
	}
	return 0;
}