#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		ll n = s.size();
		vector<ll> ones(n+1);
		vector<ll> zeros(n+1);
		ones[0] = zeros[0] = 0;
		for(int i = 1; i<=n; i++){
			ones[i] = ones[i-1];
			if(s[i-1] == '1'){
				ones[i]++;
			}
			zeros[i] = i-ones[i];
		}
		ll res = n;
		for(int i = 1; i<=n; i++){
			res = min(res,ones[i]+zeros[n]-zeros[i]);
			res = min(res,zeros[i]+ones[n]-ones[i]);
		}
		cout<<res<<endl;
	}
}
