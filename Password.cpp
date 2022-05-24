#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> kmpPreprocess(string s){
    ll n = s.size();
    vector<ll> prefix(n);
    ll j = 0;
    for(int i = 1; i<n; i++){
        while(j>0 && s[i] !=s[j]){
            j = prefix[j-1];
        }
        if(s[i] == s[j]) j++;
        prefix[i] = j;
    }
    return prefix;
}

int main(){
    string s;
    cin>>s;

    ll n = s.size();

    vector<ll> pre = kmpPreprocess(s);
    vector<ll> prefix;
    prefix.assign(pre.begin(),pre.end());
    ll end = prefix[n-1];
    ll res = -1;
    set<ll> vals;
    for(int  i = 1;i<n-1; i++) vals.insert(prefix[i]);
    while(res == -1 && end > 0){
        if(vals.find(end) != vals.end()){
            res = end;
        } else {
            end = prefix[end-1];
        }
    }
    if(res == -1){
        cout<<"Just a legend\n";
    }
    else{
        cout<<s.substr(0,res)<<"\n";
    }
}