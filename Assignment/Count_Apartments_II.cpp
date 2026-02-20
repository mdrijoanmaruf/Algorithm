#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    if(!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for(int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<char>> vis(n, vector<char>(m, 0));
    vector<int> sizes;

    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!vis[i][j] && grid[i][j] == '.'){
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    auto p = q.front(); q.pop();
                    ++cnt;
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
                sizes.push_back(cnt);
            }
        }
    }

    if(sizes.empty()){
        cout << 0 << endl;
        return 0;
    }

    sort(sizes.begin(), sizes.end());
    for(size_t i = 0; i < sizes.size(); ++i){
        if(i) cout << ' ';
        cout << sizes[i];
    }
    cout << endl;
    return 0;
}
