#include <bits/stdc++.h>
#define ll long long 

using namespace std;

void ask(ll l, ll r){
    cout<<"? 2 "<<l<<" "<<r<<endl;
}

int main(){
    ll n,a;
    char b;
    cin>>n;
    vector<char> s(n,'#');
    ll known = 0;
    for(int i = 1; i<=n; i++){
        ask(1,i);
        cin>>a;
        if(a>known){
            cout<<"? 1 "<<i<<endl;
            cin>>b;
            s[i-1] = b;
            known++;
        }
        else{
            ll before = 1;
            set<char> isNot;
            for(int j = i-1; j>=1; j--){
                ask(j,i);
                cin>>a;
                if(a == before && isNot.find(s[j-1]) == isNot.end()){
                    s[i-1] = s[j-1];
                    break;
                }
                else{
                    isNot.insert(s[j-1]);
                }
                before = a;
            }
        }
    }
    cout<<"! ";
    for(auto c : s){
        cout<<c;
    }
    cout<<endl;

}