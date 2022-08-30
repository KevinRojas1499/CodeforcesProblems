#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> pi;

void prefix_function(const string & s) {
    int n = (int)s.length();
    pi.resize(n+15);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
}

int main() {
    ll q;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s,t;
    cin>>s;
    ll n = s.size();
    cin>>q;
    prefix_function(s);
    s.resize(n+15);
    while(q--){
        cin>>t;
        ll k = t.size();
        for(int i = 0; i<k; i++) s[n+i] = t[i];
        for (int i = n; i < n+k; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        for(int i = n; i<n+k; i++) {
            cout<<pi[i]<<" ";
        }
        cout<<"\n";
    }
}