#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> a(9);
ll v;

int main() {
    cin>>v;
    ll minCost = 1e6, minD;
    for(int i = 0; i<9; i++) {
        cin>>a[i];
        if(a[i]<= minCost) {
            minCost = a[i];
            minD = i+1;
        }
    } 
    ll numDigsMax = v/minCost;
    string s = "";
    for(int i = 0; i<numDigsMax; i++){
        s+=to_string(minD);
        v-=minCost;
    }
    for(int i = 0; i<numDigsMax; i++){
        for(int j = 8; j>=minD; j--){
            if(a[j]-minCost <= v){
                s[i] = '0'+j+1;
                v-=(a[j]-minCost); 
                break;
            }
        }
    }
    if(s.size() == 0) s = "-1";
    cout<<s<<"\n";
}