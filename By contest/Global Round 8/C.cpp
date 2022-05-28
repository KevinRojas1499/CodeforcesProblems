# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	ll n,a,b,c;
	cin>>n;
	set<pair<int,int>> answer;
	if(n%2 == 1){
		a = 0;
		for(int j = 0; j<(n+1)/2; j++){
			if(j>0) a = 0;                                                                                                                                                                                                                                                                                	
			for(int i = 2; i<5;i++){
				answer.insert({i+4*j,0});
				//cout<<i+4*j+a<<" "<<0<<endl;
			}
			for(int i = 2; i<5;i+=2){				
				answer.insert({i+4*j,1});
				//cout<<i+4*j+a<<" "<<1<<endl;
			}
			for(int i = 0+(j>0?1:0); i<5;i++){
				answer.insert({i+4*j,2});
				//cout<<i+4*j+a<<" "<<2<<endl;
			}
			for(int i = 0; i<3;i+=2){
				answer.insert({i+4*j,3});
				//cout<<i+4*j+a<<" "<<3<<endl;
			}
			for(int i = 0; i<3;i++){
				answer.insert({i+4*j,4});
				//cout<<i+4*j+a<<" "<<4<<endl;
			}
		}
	}
	else{
		//cout<<15+7+14*(n/2-1);
		a = 0;
		int j;
		for(j = 0; j<n/2; j++){
			if(j>0) a = 0;                                                                                                                                                                                                                                                                                	
			for(int i = 2; i<5;i++){
				answer.insert({i+4*j,0});
				//cout<<i+4*j+a<<" "<<0<<endl;
			}
			for(int i = 2; i<5;i+=2){
				answer.insert({i+4*j,1});
				//cout<<i+4*j+a<<" "<<1<<endl;
			}
			for(int i = 0+(j>0?1:0); i<5;i++){
				answer.insert({i+4*j,2});
				//cout<<i+4*j+a<<" "<<2<<endl;
			}
			for(int i = 0; i<3;i+=2){
				answer.insert({i+4*j,3});
				//cout<<i+4*j+a<<" "<<3<<endl;
			}
			for(int i = 0; i<3;i++){
				answer.insert({i+4*j,4});
				//cout<<i+4*j+a<<" "<<4<<endl;
			}
		}
		for(int i = 0+(j>0?1:0); i<3;i++){
			answer.insert({i+4*j,2});
			//cout<<i+4*j+a<<" "<<2<<endl;
		}
		for(int i = 0; i<3;i+=2){
			answer.insert({i+4*j,3});
			//cout<<i+4*j+a<<" "<<3<<endl;
		}
		for(int i = 0; i<3;i++){
			answer.insert({i+4*j,4});
			//cout<<i+4*j+a<<" "<<4<<endl;
		}
	}
	cout<<answer.size()<<endl;
	for(auto a: answer){
		cout<<a.first<<" "<<a.second<<endl;
	}
	
	
}

