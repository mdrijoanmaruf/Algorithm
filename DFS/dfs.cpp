#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void dfs(int src){
    cout << src << " ";
    visited[src] = true;

    for(int child : adj_list[src]){
        if(visited[child] == false){
            dfs(child);
        }
    }
}

int main() {
    // Input Vertex , Edge
    int n , e;
    cin >> n >> e;

    // Input Graph
    while(e--){
        int a , b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited , false , sizeof(visited));

    // Call DFS
    dfs(0);

    return 0;
}