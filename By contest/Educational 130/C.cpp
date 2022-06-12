#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t,n;
    string s1,s2;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s1>>s2;
        ll ptr = 0;
        queue<char> reserve;
        bool possible = true;
        for(int i = 0; i<n; i++){
            bool found = false;
            while(!found && possible){
                if(reserve.size()){
                    if(reserve.front() == 'b' && s1[i] == 'c') possible = false;
                    else if (reserve.front() == 'c' && s1[i] == 'a') possible = false;
                }
                if(reserve.size() && s1[i] == reserve.front()){
                    reserve.pop();
                    found = true;
                }
                else if(ptr< n && s1[i] == s2[ptr]){
                    ptr++;
                    found = true;
                }
                else{
                    if(ptr >= n){
                        if(s1[i] == reserve.front()){
                            reserve.pop();
                            found = true;
                        }
                        else{
                            possible = false;
                        }
                    }
                    else{
                        if(s1[i] == 'a' && s2[ptr] == 'b'){
                            if(reserve.size() == 0 || reserve.front() == 'b'){
                                reserve.push('b');
                                ptr++;
                            }
                            else{
                                possible = false;
                            }
                        }
                        else if(s1[i] == 'b' && s2[ptr] == 'c'){
                            if(reserve.size() == 0 || reserve.front() == 'c'){
                                reserve.push('c');
                                ptr++;
                            }
                            else{
                                possible = false;
                            }                        
                        }
                        else{
                            possible = false;
                        }
                    }
                }                
            }
        }
        if(possible){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}