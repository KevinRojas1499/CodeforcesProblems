# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,k,aa,z;
	cin>>n>>k;
	vector<pair<ll,ll>> a(n+1);
	vector<bool> chosen(n+1,0);
	for(int i = 1; i<=n; i++){
		cin>>aa;
		a[i] = {aa,i};
	}	
	a[0] = {-1,-1};
	sort(a.begin(),a.end());
	if(k == 3){
		if(a[1].second == 1) cout<< a[2].first<<endl;
		else cout<<a[1].first<<endl;
	}
	else{
		if(k%2 == 1) z = k-1;
		else z = k;
		ll r = 1;
		ll i = 2;
		vector<ll> res;
		res.push_back(a[1].first);
		chosen[a[1].second] = 1;
		while(r<z/2){
			ll ind = a[i].second; 
			if(chosen[ind+1] == 0 && chosen[ind-1] == 0){
				chosen[ind] = 1;
				res.push_back(a[i].first);
				i++;
				r++;
			}
			else{
				i++;
			}
		}
		/*
		for(auto r: res){
			cout<<r<<" ";
		}
		cout<<endl;
		*/
		if(k%2==1 && chosen[n] == 1){
			while(r<z/2+1){
				ll ind = a[i].second; 
				if(chosen[ind+1] == 0 && chosen[ind-1] == 0){
					chosen[ind] = 1;
					res.push_back(a[i].first);
					i++;
					r++;
				}
				else{
					i++;
				}
			}
		}
		sort(res.begin(),res.end());
		cout<<res[res.size()-1]<<endl;
	}
}
