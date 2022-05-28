# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2 == 0){
			cout<<n/2;
		}
		else{
			cout<<(n-1)/2;
		}
		cout<<endl;
	}
}

