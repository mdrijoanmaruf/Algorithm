#include <bits/stdc++.h>
using namespace std;

int main(){


    int n, m;
    if(!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<char>> vis(n, vector<char>(m, 0));
    int components = 0;

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j] && grid[i][j] == '.'){
                // new component
                components++;
                // bfs
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    auto p = q.front(); q.pop();
                    int ci = p.first, cj = p.second;
                    for(int k = 0; k < 4; ++k){
                        int ni = ci + di[k];
                        int nj = cj + dj[k];
                        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        if(vis[ni][nj]) continue;
                        if(grid[ni][nj] != '.') continue;
                        vis[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }

    cout << components << endl;
    return 0;
}
