#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int n = s.size();
		int res = 0;
		for(int i = 0; i<n; i++){
			string cur3 = s.substr(i,3);
			string cur2 = s.substr(i,2);
			//cout<<"Voy por "<<i<<" con "<<cur3<<" "<<cur2<<"\n";
			if(s[i] == '.') continue;
			if(cur3.size()==3 && cur3[0] == cur3[2]){
				s[i+2] = '.';
				res++;
			}
			if(cur2.size() == 2 && cur2[0] == cur2[1]){
				res++;
				s[i+1] = '.';
			}
		}
		//cout<<s<<"\n";
		cout<<res<<"\n";			
	}
}
