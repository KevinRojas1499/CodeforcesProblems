#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isType1(string s){
	ll n = s.size();
	ll r = -1,c = -1;
	for(int i = 0; i<n; i++){
		if(s[i] == 'R' && r == -1){
			r = i;
		}
		else if(s[i] == 'C' && c == -1){
			c = i;
		}
	}
	return (r>=0 && c>=0 && abs(r-c)>1);
} 

string column(string s){
	ll a = stoi(s);
	ll b = 1;
	ll exp = 0;
	while(b<=a){
		b*=26;
		exp++;
	}
	b/=26;exp--;
	string res = "";
	for(int i = 0; i<exp; i++) res+="A";
	ll i = 0;
	while(a>0){
		ll c = a/b;
		res[i] =  ('A'+c);
		a-=c*b;
		b/=26;	
		i++;	
	}
	return res;
}

int val(string s){
	ll n = s.size();
	ll res = 0;
	ll cur = pow(26,n-1);
	for(int i = 0; i<n; i++){
		res+=cur*(s[i]-'A');
		cur/=26;
	}
	return res;
}

int main(){
	ll t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		if(isType1(s)){
			string R = "";
			ll i = 1;
			while(s[i] != 'C'){
				R+= s[i];
				i++;
			}
			string C = s.substr(i+1);
			cout<<column(C)<<R<<"\n";
		}
		else{ 
			string let = "";
			ll i = 0;
			while(isalpha(s[i])){
				let+=s[i];
				i++;
			}
			string num = s.substr(i);
			cout<<"R"<<num<<"C"<<val(let)<<'\n';
			
		}
		
	}
}
