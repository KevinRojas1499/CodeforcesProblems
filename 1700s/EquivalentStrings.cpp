#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s1,s2;

bool isEquivalent(string a, string b){
    if(a == b) return true;
    else {
        if(a.size()%2 == 0){
            ll n = a.size();
            string a1 = a.substr(n/2);
            string a2 = a.substr(0,n/2);
            string b1 = b.substr(n/2);
            string b2 = b.substr(0,n/2);
            return (isEquivalent(a1,b1) && isEquivalent(a2,b2) )|| (isEquivalent(a1,b2) && isEquivalent(a2,b1)); 
        }
        else{
            return false;
        }
    }
}

int main (){
    cin>>s1>>s2;
    if(isEquivalent(s1,s2)) cout<<"YES\n";
    else cout<<"NO\n";
}