#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll mxN = 5e6+5;
ll isPrime[mxN], numDiv[mxN], accum[mxN];

int main() {
    ll t,a,b;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    memset(numDiv, 0, sizeof numDiv);
    memset(isPrime,0,sizeof isPrime);
    memset(accum, 0, sizeof accum);
    vector<ll> primes;
    for(int i = 2; i<=5e6; i++){
        if(isPrime[i] == 0) {
            isPrime[i] = i;
            primes.push_back(i); 
        }
        else continue;
        for(int j = 2*i; j<=5e6; j+=i){
            if(isPrime[j] == 0) isPrime[j] = i;
        }
    }
    for(int i =  2; i<=5e6; i++){
        ll x = i, p = isPrime[i];
        while(x%p == 0){
            numDiv[i]++;
            x/=p;
        }
        numDiv[i]+=numDiv[x];
    }
    for(int i = 1; i<=5e6; i++){
        accum[i] = accum[i-1]+numDiv[i];
    }
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<accum[a]-accum[b]<<"\n";
    }
}