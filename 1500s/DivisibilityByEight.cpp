#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	string s;
	cin>>s;
	s = "00"+s;
	int n = s.size();
	
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			for(int k = j+1; k<n; k++){
				string cur = "";
				cur+=s[i];
				cur+=s[j];
				cur+=s[k];
				int val = stoi(cur);
				if(val%8 == 0){
					cout<<"YES\n"<<val<<'\n';
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
}
