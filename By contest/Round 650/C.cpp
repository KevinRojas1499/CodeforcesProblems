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
		cin>>n>>k;
		int nextOne[n];
		cin>>s;
		res = 0;
		cur = -1;
		for(int i = n-1; i>=0; i--){
			if(s[i] == '1'){
				nextOne[i] = cur;
				cur= i;
			}
			else nextOne[i] = cur;
		}
		/*
		cout<<"Unos\n";
		for(int i = 0; i<n; i++){
			cout<<nextOne[i]<<" ";
		}
		cout<<'\n';
		*/
		for(int i = 0; i<n; i++){
			if(s[i]== '1' ){
				i+=k;
			}
			else if(nextOne[i] == -1 || nextOne[i]-i>k){
				res++;
				i+=k;
				
			}
		}
		cout<<res<<'\n';
			
	}
}

