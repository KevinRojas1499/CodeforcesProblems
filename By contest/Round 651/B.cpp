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
		vector<int> a(2*n+1);
		for(int i  = 1; i<=2*n; i++)
			cin>>a[i];
		vector<pair<ll,ll>> pares;
		vector<pair<ll,ll>> impares;
		for(int i = 1; i<2*n+1; i++){
			if(a[i]%2==0){
				pares.push_back({a[i],i});
			}
			else{
				impares.push_back({a[i],i});
			}
		}
		ll r = 0;
		ll cp = 0;
		ll ci = 0;
		//cout<<"TENGO PARES "<<pares.size()<<endl;
		/*
		for(auto a: pares){
			cout<<a.first<<" ";
		}
		cout<<endl;
		*/
		ll b= 0;
		if(pares.size()%2 ==1)b = -1;
		
		while(r<n-1 && cp<pares.size()+b){
			//cout<<"ENTRE A LOS PARES\n";
			cout<<pares[cp].second<<" "<<pares[cp+1].second<<endl;
			cp+=2;
			r++;
		}
		while(r<n-1){
			//cout<<"ENTRE A LOS IMPARES\n";
			cout<<impares[ci].second<<" "<<impares[ci+1].second<<endl;
			ci+=2;
			r++;
		}
				
	}
}

