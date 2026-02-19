#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        // 1. Bring out
        int parent = q.front();
                                          
        q.pop();

        // 2. Work with this
        cout << parent << " ";

        // 3. Push Children
        for(int child : adj_list[parent]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }

    }
}

int main() {
    int n , e;
    cin >> n >> e;

    while(e--){
        int a , b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited , false , sizeof(visited));

    bfs(0);
    return 0;
}