#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t;
    vector<char> s(4);
    cin>>t;
    while(t--){
        cin>>s[0]>>s[1]>>s[2]>>s[3];
        sort(s.begin(),s.end());
        if(s[0] == s[3]) cout<<"0\n";
        else if (s[0] == s[2]) cout<<"1\n";
        else if(s[0] == s[1] && s[2] == s[3]) cout<<"1\n";
        else if(s[0] == s[1]) cout<<"2\n";
        else if(s[1] == s[3]) cout<<"1\n";
        else if(s[1] == s[2]) cout<<"2\n";
        else if(s[2] == s[3]) cout<<"2\n";
        else cout<<"3\n";

    }
}