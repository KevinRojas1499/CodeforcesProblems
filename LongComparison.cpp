#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,x1,p1,x2,p2;
    cin>>t;
    while(t--){
        cin>>x1>>p1;
        cin>>x2>>p2;
        ll dig1 = log10(x1);
        ll dig2 = log10(x2);
        while(dig1 < dig2 && p1){
            x1*=10;
            p1--;
            dig1++;
        }
        while(dig2 < dig1 && p2){
            x2*=10;
            p2--;
            dig2++;
        }
        if(p1 > p2){
            cout<<">";
        }
        else if (p2>p1){
            cout<<"<";
        }
        else{
            if(x1 > x2){
                cout<<">";
            }
            else if(x1 < x2){
                cout<<"<";
            }
            else{
                cout<<"=";
            }
        }
        cout<<"\n";
    }
}