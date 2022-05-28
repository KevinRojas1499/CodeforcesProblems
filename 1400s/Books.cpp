#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,t;
	cin>>n>>t;
	int a[n];
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	a[0] = 0;	
	int i,j = 0;
	ll curr = 0;
	for(i = 0; j<=n; i++,j++){
		curr+=a[j];
		curr-=a[i];
		while(j<n && curr+a[j+1]<= t){
			curr+=a[j+1];
			j++;
		}
	}
	cout<<j-i<<endl;
}
