#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
int n, m;
int des_i = -1, des_j = -1;
bool found = false;

vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    return true;
}

void dfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si, sj});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int i = cur.first, j = cur.second;
        if(!valid(i,j)) continue;
        if(visited[i][j]) continue;
        if(grid[i][j] == '#') continue; // wall

        visited[i][j] = true;
        if(i == des_i && j == des_j){
            found = true;
            return;
        }

        for(int k = 0; k < 4; k++){
            int ni = i + d[k].first;
            int nj = j + d[k].second;
            if(valid(ni,nj) && !visited[ni][nj] && grid[ni][nj] != '#'){
                q.push({ni,nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) grid[i][j] = s[j];
    }

    int src_i = -1, src_j = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                src_i = i; src_j = j;
            } else if(grid[i][j] == 'B'){
                des_i = i; des_j = j;
            }
        }
    }

    if(src_i == -1 || des_i == -1){
        cout << "NO" << '\n';
        return 0;
    }

    memset(visited, false, sizeof(visited));
    dfs(src_i, src_j);

    if(found) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}