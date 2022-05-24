#include <bits/stdc++.h> 
#define ll long long

using namespace std;

ll test,h,c;

double temp(ll n){
	ll k = n/2;
	if(n%2 == 0){
		return (double)(h+c)/2;
	}
	else{
		return (double)(h+k*c+k*h)/n;
	}
}

int main(){	
	double t;
	cin>>test;
	while(test--){
		cin>>h>>c>>t;
		ll a = 0;
		ll b = h;
		while(a<=b){
			ll d = (a+b)/2;
			if(temp(2*d+1) == t){
				a = d;
				break;
			}
			else if(temp(2*d+1)>t){
				a = d+1;
			}
			else{
				b = d-1;
			}
		}
		ll res = fabs(temp(2*a+1)-t)<=fabs(temp(2*a+3)-t)? 2*a+1 : 2*a+3;
		res = fabs(temp(res)-t)<fabs(temp(2*a-1)-t)? res : 2*a-1;
		if(fabs(temp(res)-t)<fabs(temp(2)-t)){
			cout<<res;
		}
		else if(fabs(temp(res)-t)==fabs(temp(2)-t) && res == 1){
			cout<<1;
		}
		else{
			cout<<2;
		}
		cout<<endl;
	}
}
