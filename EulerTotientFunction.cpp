Program 14: Implement Euler-Totient (Phi) Function
#include<bits/stdc++.h>
using namespace std;
int phi(int num){
    vector<int> val(num+1);
    int i,p;
    for(i=1;i<=num;i++)
        val[i]=i;
    for(p=2;p<=num;p++){
        if(val[p]==p){
            val[p]=p-1;
            for(i=2*p;i<=num;i+=p)
                    val[i]=(val[i]/p)*(p-1);
        }
    }
    return val[num];
}
int main(){
    cout<<"Enter the value"<<endl;
    int num;
    cin>>num;
    int totient=phi(num);
    cout<<"The value of phi("<<num<<") is: "<<totient<<endl;
    return 0;
}