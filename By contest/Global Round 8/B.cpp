# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	ll t,n,a,b,c;
	cin>>t;
	a = ceil(log2(t));
	b = a%10;
	c = (a-b)/10;
	vector<int> count(10,c);
	n = 0;
	while(b!=0){
		count[n]++;
		n++;
		b--;
	}
	for(int i  = 0; i< pow(2,count[0]); i++)
		cout<<"c";
	for(int i  = 0; i< pow(2,count[1]); i++)
		cout<<"o";
	for(int i  = 0; i< pow(2,count[2]); i++)
		cout<<"d";
	for(int i  = 0; i< pow(2,count[3]); i++)
		cout<<"e";
	for(int i  = 0; i< pow(2,count[4]); i++)
		cout<<"f";
	for(int i  = 0; i< pow(2,count[5]); i++)
		cout<<"o";
	for(int i  = 0; i< pow(2,count[6]); i++)
		cout<<"r";
	for(int i  = 0; i< pow(2,count[7]); i++)
		cout<<"c";
	for(int i  = 0; i< pow(2,count[8]); i++)
		cout<<"e";
	for(int i  = 0; i< pow(2,count[9]); i++)
		cout<<"s";
	cout<<endl;
}

