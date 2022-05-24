#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,t,a,b;
	cin>>n;
	string s;
	cin>>s;
	vector<char> res;
	for(int i = 0; i<n; i++){
		if(s[i] == '0' || s[i] == '1'){
			continue;
		}
		else if(s[i] == '2' || s[i] == '3'|| s[i] == '5' ||s[i] == '7'){
			res.push_back(s[i]);
		}
		else if(s[i] == '4'){
			res.push_back('3');
			res.push_back('2');
			res.push_back('2');
		}
		else if(s[i] == '6'){
			res.push_back('5');
			res.push_back('3');
		}
		else if(s[i] == '8'){
			res.push_back('7');
			res.push_back('2');
			res.push_back('2');
			res.push_back('2');
		}
		else if(s[i] == '9'){
			res.push_back('7');
			res.push_back('3');
			res.push_back('3');
			res.push_back('2');
		}
	}
	sort(res.rbegin(),res.rend());
	for(int i = 0; i< res.size(); i++){
		cout<<res[i];
	}
	cout<<endl;
	
}
