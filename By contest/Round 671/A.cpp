#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n,par,impar;
	cin>>t;
	string s;
	while(t--){
		cin>>n;
		cin>>s;
		par = 0;
		impar = 0;

		if(n%2==0){
			for(int i = 1; i<n; i+=2){
				int num = (int)s[i];
				if(num%2==0){
					par++;
				}
				else{
					impar++;
				}
			}
			//cout<<par<<" "<<impar<<endl;
			if(par>0)
				cout<<"2\n";
			else
				cout<<"1\n";
		}
		else if(n == 1){
			int num = (int) s[0];
			if(num%2 ==0){
				cout<<"2\n";
			}
			else{
				cout<<"1\n";
			}
		}
		else{
			for(int i = 0; i<n; i+=2){
				int num = (int)s[i];
				if(num%2==0){
					par++;
				}
				else{
					impar++;
				}
			}
			//cout<<par<<" "<<impar<<endl;
			if(impar>0)
				cout<<"1\n";
			else
				cout<<"2\n";
		}
	}
}
	
