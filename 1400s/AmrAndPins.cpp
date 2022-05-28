#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll a,b,x,y,r;
	
	cin>>r>>a>>b>>x>>y;
	double d = sqrt((a-x)*(a-x)+(b-y)*(b-y));
	double res = d/(2.0*r);
	cout<<ceil(res)<<endl;
	
}
