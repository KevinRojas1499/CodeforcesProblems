#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll t,n;
    string a,b;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b;
        bool reversed = false;
        ll back = n-1,front = 0;
        vector<ll> operations;
        for(int i = n-1; i>=0; i--){
            if(!reversed){
                if(b[i] == a[front]){
                    operations.push_back(1);
                }
                front++;
            }
            else {
                if(b[i] != a[back]){
                    operations.push_back(1);
                }
                back--;
            }
            operations.push_back(i+1);
            reversed = !reversed;
        }
        cout<<operations.size()<<"\n";
        for(auto v : operations){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}