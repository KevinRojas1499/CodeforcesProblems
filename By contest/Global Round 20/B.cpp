#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        set<ll> letters;
        for(auto c : s) letters.insert(c);
        vector<ll> numA(n),numB(n);
        numA[0] = s[0] == 'A' ? 1 : 0;
        numB[0] = s[0] == 'B' ? 1 : 0;
        for(int i = 1; i<n; i++){
            if(s[i] == 'A'){
                numA[i] = 1 + numA[i-1];
                numB[i] = numB[i-1];
            }
            else {
                numA[i] = numA[i-1];
                numB[i] = 1 + numB[i-1];
            }
        }
        bool possible = true;
        for(int i = 0; i<n; i++){
            if(numB[i]>numA[i]) possible = false;
        }
        if(possible && letters.size() == 2 && s[n-1] == 'B'){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

}