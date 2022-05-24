# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t,n,a,p,im;
	cin>>t;
	while(t--){
		cin>>n;
		p = im = 0;
		for(int i = 0; i<n; i++){
			cin>> a;
			if(a%2 == 0 && a%2 != i%2){
				p++;
			}
			else if(a%2 == 1 && a%2 != i%2) im++;
		}
		if(im == p) cout<< p<<'\n';
		else cout<<"-1\n";
	}
}

