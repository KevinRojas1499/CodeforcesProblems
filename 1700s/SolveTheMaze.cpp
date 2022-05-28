#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, n, m;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
bool isIn(ll x, ll y) { return 0 <= x && x < n && 0 <= y && y < m; }

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        char mat[n][m];
        bool pos[n][m], seen[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                pos[i][j] = 0;
                seen[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        ll x = i + dx[k], y = j + dy[k];
                        if (isIn(x, y) && mat[x][y] != 'G' && mat[x][y] != 'B') {
                            mat[x][y] = '#';
                        }
                    }
                }
            }
        }

        queue<pair<ll, ll>> q;
        q.push({n - 1, m - 1});
        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            if(mat[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                ll x = i + dx[k], y = j + dy[k];
                if (isIn(x, y) && !seen[x][y] && mat[x][y] != '#') {
                    pos[x][y] = 1;
                    q.push({x,y});
                    seen[x][y] = 1;
                }
            }
        }
        bool goodOnes = true, badOnes = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(mat[i][j] == 'G' && !pos[i][j]) goodOnes = false;
                if(mat[i][j] == 'B' && pos[i][j]) badOnes = true;
            }
        }
        if((goodOnes && !badOnes)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}