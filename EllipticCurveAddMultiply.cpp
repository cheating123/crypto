
Program 21: Perform Addition and Multiplication on Elliptic Curve
#include<bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y){
    if(a == 0){
		*x = 0, *y = 1;
		return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int modInverse(int a, int m){
	int x, y;
	int g = gcdExtended(a, m, &x, &y);
	int res = INT_MIN;
	if (g == 1){
		res = (x%m + m) % m;
	}
	return res;
}
int get_lambda(int x1, int y1, int x2, int y2, int a, int p){
	int lambda = 0;
	if(x1==x2 && y1!=y2)
		return -1;
	if(x1==x2 && y1==y2){
		lambda = (((3*x1*x1)%p)+a)%p;
		int y = (2*y1)%p;
		int y_inverse = modInverse(y, p);
		lambda = lambda*y_inverse;
		lambda %= p;
    }else{
		int y = (y2-y1)%p;
		int x = (x2-x1)%p;
		int x_inverse = modInverse(x, p);
		lambda = (y*x_inverse)%p;
    }
    return lambda;
}
int x_sum(int lambda, int x1, int x2, int p){
	int x = (lambda*lambda)%p;
    x = (x - x1 - x2)%p;
    if(x<0)
		x = x + p;
    return x;
}
int y_sum(int lambda, int x1, int x3, int y1, int p){
	int y = ((lambda*(x1-x3))%p-y1)%p;
	if(y<0)
		y = y + p;
    return y;
}
pair<int,int> sum(int x1, int y1, int x2, int y2, int a, int p){
	if(x1==-1)
		return {x2,y2};
	if(x2==-1)
		return {x1,y1};
    int lambda = get_lambda(x1, y1, x2, y2, a, p);
    if(lambda ==-1)
    	return {-1,0};
    int x3 = x_sum(lambda, x1, x2, p);
    int y3 = y_sum(lambda, x1, x3, y1, p);
    return {x3,y3};
}
pair<int,int> multiply(int x, int y, int times, int a, int p){
	int x_ans = x, y_ans = y;
    int i,j,k;
    for(i=0;i<times-1;i++){
		pair<int,int> pp = sum(x_ans, y_ans, x, y, a, p);
		x_ans = pp.first;
		y_ans = pp.second;
    }
    return {x_ans,y_ans};
}
int main(){
	int y_squared,p,a,b;
	cout<<"Enter the values of p, a and b"<<endl;
	cin>>p>>a>>b;
	cout<<endl<<"Enter the points to be added (first set of coordinates followed by second set)"<<endl;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	pair<int,int> point=sum(x1, y1, x2, y2, a, p);
	cout<<"The sum is: ("<<point.first<<","<<point.second<<")"<<endl;
	int x3,y3,times;
	cout<<"Enter the points to be multiplied followed by number of times"<<endl;
	cin>>x3>>y3>>times;
	pair<int,int> prod=multiply(x3, y3, times, a, p);
	cout<<"The product is: ("<<prod.first<<","<<prod.second<<")"<<endl;
	return 0;
}