#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        map<string,ll> count, count2;
        bool possible = false;
        for(int i = 0; i<n; i++) {
            cin>>s;
            string s1 = s;
            sort(s1.begin(),s1.end());
            auto it = unique(s1.begin(),s1.end());
            s1.resize(distance(s1.begin(),it));
            if(s1.size() == 1) {
                possible = true;
                continue;
            }
            s1 = s;
            reverse(s1.begin(),s1.end());
            if(count[s1]) possible = true;
            if(s1.size() == 3 && s[0] == s[2]) possible = true;

            if(s1.size() == 3 && count[s1.substr(0,2)]) possible = true;
            if(s1.size() == 2 && count2[s1]) possible = true; 
            count[s]++;
            if(s.size() == 3) {
                count2[s.substr(0,2)]++;
            }
        }
        if(possible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}