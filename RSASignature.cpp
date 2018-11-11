
23. RSA DIGITAL SIGNATURE
Sol :   #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modexp(ll a,ll p,ll m)
{
   ll r=1;
   while(p!=0)
   {
      if(p&1)
        r=(r*a)%m;        a=(a*a)%m;
        p=p/2;      
   }
   return r;
}
ll extended(ll a,ll b,ll &x,ll &y){
    if(a==0)
    {  x=0; y=1;  return  b;    } 
    ll x1,y1;
    ll gcd = extended(b%a,a,x1,y1);
    x = y1-(b/a)*x1;    y = x1;
}
ll mulInverse(ll a,ll m){
    if(__gcd(a,m)!=1) 
        return -1;
     ll x,y;     ll g =  extended(a,m,x,y);
   return (x+m)%m;
}
int main()
{
	cout << "** RSA ALgorithm **\nEnter p and q:";
	ll p ,q; cin >> p >> q;
	ll n = p*q; 	ll phi = (p-1)*(q-1);
	ll e = 3;	cout << "phi ( " << n <<") = "<< phi << "\n";
	ll d;
	for(ll i=2;;i++)	{
	   d = mulInverse(i,phi);
	    if(d!=-1)  {e=i; break;}
	}
	cout << "\nEnter m :";	ll m;	cin >> m;
	cout << "\nSIGNED MESSAGE \n";
	ll sign;	cout << (sign=modexp(m,d,n)) << "\n";
	cout << "Verification : \n"; 	cout << modexp(sign,e,n) << "\n";
	return 0;
}