#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll t,n,k,sum;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> a(n);	
		set<int> values;	
		for(int i = 0; i < n; i++){
			cin>>a[i];
			values.insert(a[i]);
		}		
		if(values.size()>k){
			cout<<"-1\n";
		}
		else if (n == k){
			cout<<n<<"\n";
			for(int i = 0; i < n; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"9999\n";
			int count = 0;
			int j = 1;	
			while(values.size()!=k){
				values.insert(j);
				j++;
			}		
			while(count<9999){
				for(auto v :values){
					cout<<v<<" ";
					count++;
					if(count == 9999) break;
				}
			}			
			cout<<'\n';			
		}
	}
}
