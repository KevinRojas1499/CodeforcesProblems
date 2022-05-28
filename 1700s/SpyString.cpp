#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<string> words(n);
        for(int i = 0; i<n; i++) cin>>words[i];

        string s = words[0];
        bool possible = true;
        for(int i = 0; i<m; i++){
            possible = true;
            if(i>0) s[i-1] = words[0][i-1];
            s[i] = '#';
            bool changed = false;
            for(int j = 1; j<n; j++){
                ll numDifferences = 0;
                for(int k = 0; k<m; k++){
                    if(s[k] != '#' && s[k] != words[j][k]){
                        numDifferences++;
                    }
                }
                if(numDifferences>1){
                    possible = false;
                    break;
                }
                else if(numDifferences == 1 && !changed){
                    changed = true;
                    s[i] = words[j][i];
                }
            }
            if(possible) break;
        }
        if(possible){
            for(int i = 0; i<m; i++) if(s[i] == '#') s[i] = 'a';
            cout<<s<<"\n";
        }
        else{
            cout<<"-1\n";
        }
        
    }
}