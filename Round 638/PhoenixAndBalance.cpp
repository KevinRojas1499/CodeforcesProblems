#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t,n,sum;
	cin>>t;
	while(t--){
		cin>>n;
		sum = (1<<n);
		for(int i = 1; i <= n/2; i++){
			sum-= (1<<(n-i));
		}		
		for(int i = n/2+1; i < n; i++){
			sum+= (1<<(n-i));
		}
		cout<<sum<<'\n';
	}
}
