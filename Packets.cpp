#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    ll maxValue = 0, res = 0;
    for(int i = 1; i<n; i++){
        if(maxValue<i){
            res++;
            maxValue+=i;
        }
    }
}