#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> solution;

int dp[115][915];

bool can(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}


int main(){
	ll m,s;
	cin>>m>>s;
    int sum = s;
    string minn = "";
    string maxx = "";
    for (int i = 0; i < m; i++){
        for (int d = 0; d < 10; d++){
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
            {
                minn += char('0' + d);
                sum -= d;
                break;
            }
		}
	}
	sum = s;
    for (int i = 0; i < m; i++){
        for (int d = 9; d >= 0; d--){
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
            {
                maxx += char('0' + d);
                sum -= d;
                break;
            }
		}
	}
	if((ll)minn.size() == m && (ll)maxx.size() == m){
		cout<<minn<<" " <<maxx<<endl;
	}
	else{
		cout<<"-1 -1\n";
	}
		
}
