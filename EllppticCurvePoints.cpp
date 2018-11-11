
Program 20: Generate points on Elliptic Curve
#include<bits/stdc++.h>
using namespace std;
vector<int> find_squares(int p){
	vector<int> squared;
	for(int i=0;i<p;i++)
		squared.push_back(i*i%p);
	return squared;
}
int find_sqrt(int val, int p, vector<int> squared){
	for(int i=0;i<p;i++)
		if(squared[i]==val)
			return i;
	return -1;
}
vector<pair<int,int>> find_points(int a, int b, int p){
	vector<int> squared;
	vector<pair<int,int>> points;
	squared=find_squares(p);
	for(int i=0;i<p;i++){
		int y_squared = i*i*i + a*i +b;
		y_squared%=p;
		int root = find_sqrt(y_squared,p,squared);
		if(root==-1)
			continue;
		points.push_back({i,root});
		if(root!=(p-root)%p)
			points.push_back({i,(p-root)%p});
	}
	return points;
}
int main(){
	int y_squared,p,a,b;
	cout<<"Enter the values of p, a and b"<<endl;
	cin>>p>>a>>b;
	vector<pair<int,int>> points=find_points(a,b,p);
	cout<<"The points on the curve are:";
	for(auto point:points)
		cout<<"("<<point.first<<","<<point.second<<") ";
	return 0;
}