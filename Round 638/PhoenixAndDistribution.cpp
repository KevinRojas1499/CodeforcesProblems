#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t,n,k,sum;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>s;
		vector<int> count(28);
		vector<string> str(k);  
		for(int i = 0; i < s.size(); i++){
			count[s[i]-'a']++;
		}
		int a = 0;
		for(int i = 0; i < 28; i++){
			a += k;
			a%=k;
			int m = count[i]/k;
			while(count[i] != 0){
				if(count[i] < m){
					str[k-1]+=('a'+i);
					count[i]--;
				}
				else{					
					for(int g = 0; g < m; g++){
						str[a]+=('a'+i);
						count[i]--;
					}								
					a++;
					a+=k;
					a%=k;
				}
			}
			a = 0;
		}
		sort(str.begin(),str.end());
		cout<<"Aqui voy\n";
		for(int i = 0; i < k; i++){
			cout<<i<<" "<<str[i]<<'\n';
		}
		cout<<str[k-1]<<'\n';
	}
}
