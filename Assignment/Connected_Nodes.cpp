#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

int main() {
    int n , e;
    cin >> n >> e;

    while(e--){
        int a , b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int x;
    cin >> x;
    while(x--){
        int a;
        cin >> a;

        if (adj_list[a].empty()){
            cout << -1 << endl;
        } else {
            sort(adj_list[a].begin(), adj_list[a].end() , greater<int>());
            for(int child : adj_list[a]){
                cout << child << " ";
            } cout << endl;
        }
    }
    return 0;
}