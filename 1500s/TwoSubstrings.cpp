#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	string s;
	cin>>s;
	int n= s.size();
	int ab = 0, ba = 0, aba = 0, bab = 0;
	for(int i = 0; i < n; i++){
		string dos = s.substr(i,2);
		string tres = s.substr(i,3);
		if( dos == "AB"){
			ab++;
		}
		else if(dos == "BA"){
			ba++;
		}
		if(tres == "ABA"){
			aba++;
		}
		else if(tres  == "BAB"){
			bab++;
		}
	}
	if(ab == 2 && ba == 1 && bab == 1 && aba == 1){
		cout<<"NO\n";
	}
	else if(ab == 1 && ba == 2 && bab == 1 && aba == 1){
		cout<<"NO\n";
	}
	else if(ab == 1 && ba == 1 && ((bab == 1 && aba == 0) || (aba == 1 && bab == 0) )){
		cout<<"NO\n";
	}
	else if(ab>0 && ba>0){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}















