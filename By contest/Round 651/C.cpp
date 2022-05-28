# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%2 ==1){
			if(n!= 1)
				cout<<"Ashishgup\n";
			else
				cout<<"FastestFinger\n";
		}
		else{
			if(n == 2)cout<<"Ashishgup\n";
			else if(n == pow(2,floor(log2(n))) ) cout<<"FastestFinger\n";
			else if(n%4  ==0){
				cout<<"Ashishgup\n";
			}
			else{
				n/=2;
				ll npri = 0;
				for(int i = 3; i<=sqrt(n);i++){
					if(n%i == 0){
						npri = 1;
						break;
					}
				}
				if(npri == 1)
					cout<<"Ashishgup\n";
				else
					cout<<"FastestFinger\n";
			}
		}
	}
}

