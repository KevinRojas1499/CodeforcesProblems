# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t,n,k,res,cur;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		cin>>n;
		vector<pair<int,int>> b(n);
		char res[n];
		for(int i = 0; i< n; i++){
			cin>>k;
			b[i] = {k,i};
		}
		sort(b.begin(),b.end());
		sort(s.rbegin(),s.rend());
		
		for(int i = 0; i<n; i++)
			cout<<b[i].first<<" ";
		cout<<" "<<s<<'\n';
		
		for(int i = 0; i<n; i++){
			res[b[i].second] = s[i];
		}
	}
}
