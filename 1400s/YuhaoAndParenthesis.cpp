#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){
    ll n;
    cin>>n;
    string s;
    vector<ll> open(n), closed(n);
    for(int i = 0; i<n; i++){
        cin>>s;
        queue<char> q;
        for(int j = 0; j<(ll) s.size(); j++){
            if(s[j] == ')' && (q.front() != '(' || q.size() == 0)){
                closed[i]++;
            }
            else if(s[j] == ')') {
                q.pop();
            }
            else{
                q.push('(');
            }
        }
        open[i] = q.size();
        if(open[i] != 0 && closed[i] != 0) {
            open[i] = -1;
            closed[i] = -1;
        }
    }
    map<ll,ll> countOpen, countClosed;
    ll good = 0;
    for(int i = 0; i<n; i++){
        countOpen[open[i]]++;
        countClosed[closed[i]]++;
        if(open[i] == closed[i] && open[i] == 0){
            good++;
        }
    }
    ll res = 0;
    for(auto [key, count] : countOpen){
        if(key == 0 || key == -1) continue;
        res+= min(count,countClosed[key]);
    }
    res+=(good/2);
    cout<<res<<"\n";
}