#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> h(n);
        for(int i = 0; i<n; i++) {
            cin>>h[i];
        }
        sort(h.begin(),h.end());
        ll maxx = h[n-1];
        ll res = 1;
        for(int i = 0; i<n-1; i++){
            cout<<"BEGIN "<<res<<"\n";
            ll needed = maxx-h[i];
            cout<<"NEED "<<needed<<"\n";
            if(needed == 0) continue;
            res+= 2*(needed/3);
            if(needed%3 == 1 || needed%3 == -2){
                cout<<"MOD1"<<endl;
                if(res%2 == 0){
                    res++;
                    if(h[i+1]+2<=maxx) {
                        h[i+1]+=2;
                    } 
                }
                res++;

            }
            else if(needed%3 == 2 || needed%3 == -1){
                cout<<"MOD2 "<<res<<"\n";
                if(res%2 != 0){
                    cout<<"DAY "<<res<<endl;
                    res++;
                    if(h[i+1] + 1 <= maxx){
                        h[i+1]++;
                    }
                }
                res++;
            }
            cout<<"END   "<<res<<"\n";
        }
        cout<<res-1<<"\n";



    }
}