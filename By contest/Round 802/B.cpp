#include <bits/stdc++.h>
#define ll long long

using namespace std;

string addStrings(string num1, string num2) {
        string r = "";
        int sz1 = static_cast<int>(num1.size());
        int sz2 = static_cast<int>(num2.size());
        int i = 0, j = 0, c = 0;
        while (i < sz1 || j < sz2 || c > 0) {
            int t = c;
            t += i < sz1 ? num1[sz1 - i - 1] - 48 : 0;
            t += j < sz2 ? num2[sz2 - j - 1] - 48 : 0;
            r = string(1, t % 10 + 48) + r;
            c = t / 10; // carry over next digit
            i ++;
            j ++;
        }
        return r;
}
string findDiff(string str1, string str2) {
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) {
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
 

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    string s;
    while(t--){
        cin>>n;
        cin>>s;
        vector<char> a(n,1);
        string M(n,'9'), m(n,'0');
        m[0] = '1';
        string Ma = addStrings(s,M), ma = addStrings(s,m);
        string b(ma.size(),'0');
        bool bigger = 0;
        ll k = b.size();
        for(int i = 0; 2*i<n; i++){
            if(bigger) b[i] = b[k-1-i] = '0';
            else if(i == 0) b[i] = b[k-1-i] = ma[0];
            else{
                b[i] = b[k-1-i] = max(ma[i],ma[k-1-i]);
                if(b[i] > ma[i]) bigger = true;
            }
        }
        if(k%2 != 0) b[k/2] = '9';
        bool firstNonZero = 0;
        for(auto c : findDiff(b,s)){
            if(!firstNonZero && c == '0') continue;
            firstNonZero = true;
            cout<<c;
        }
        cout<<"\n";



    }
}