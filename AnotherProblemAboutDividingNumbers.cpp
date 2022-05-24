#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> primes;
ll numPrimes;


ll numberOfDivisors(ll a){
    ll divA = 0;
    for(int i = 0; i<numPrimes && a > 1; i++){
        ll p = primes[i];
        if(p*p > a) {
            divA++;
            break;
        }
        while(a%p == 0){
            a/=p;
            divA++;
        }
    }
    return divA;
}

int main() {
    ll t,a,b,k;
    cin>>t;
    vector<bool> isPrime(1e7,true);
    for(int i = 2; i<1e6; i++){
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j<1e6; j+=i) isPrime[j] = false;
        }
    }
    numPrimes = primes.size();
    while(t--){
        cin>>a>>b>>k;
        ll divA = numberOfDivisors(a);
        ll divB = numberOfDivisors(b);
        // cout<<a<<" "<<divA<<" "<<b<<" "<<divB<<"\n";
        if(k == 1){
            if(a!=b && (a%b == 0 || b%a == 0)) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else{
            if(divA+divB >= k){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
}