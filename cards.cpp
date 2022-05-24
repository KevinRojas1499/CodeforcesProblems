#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<char,ll> letters;
    set<char> let;
    for(int i = 0; i<n; i++){
        letters[s[i]]++;
        let.insert(s[i]);
    }
    if(let.size() == 3){
        cout<<"BGR\n";
    }
    else if(let.size() == 2){
        ll blue = letters['B'];
        ll red = letters['R'];
        ll green = letters['G'];
        if(blue == 0){
            if(red>1 && green>1){
                cout<<"BGR\n";
            }
            else if(red == 1 && green == 1){
                cout<<"B\n";
            }
            else{
                if(red == 1){
                    cout<<"BR\n";
                }
                else{
                    cout<<"BG\n";
                }
            }
        }
        if(red == 0){
            if(blue > 1 && green > 1){
                cout<<"BGR\n";
            }
            else if(blue == 1 && green == 1){
                cout<<"R\n";
            }
            else{
                if(blue == 1){
                    cout<<"BR\n";
                }
                else{
                    cout<<"GR\n";
                }
            }
        }
        if(green == 0){
            if(blue > 1 && red > 1){
                cout<<"BGR\n";
            }
            else if(blue == 1 && red == 1){
                cout<<"G\n";
            }
            else{
                if(blue == 1){
                    cout<<"BG\n";
                }
                else{
                    cout<<"GR\n";
                }
            }
        }
    }
    else{
        cout<<*let.begin()<<"\n";
    }
}