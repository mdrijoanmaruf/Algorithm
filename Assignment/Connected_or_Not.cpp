#include <bits/stdc++.h>
using namespace std;
unordered_set<int> adj_list[1005];
int n , e;

int main() {
    cin >> n >> e;

    while(e--){
        int a , b;
        cin >> a >> b;
        adj_list[a].insert(b);
    }

    int x;
    cin >> x;
    while(x--){
        int a , b;
        cin >> a >> b;
        bool check = false;

        if(a == b){
            check = true;
        } 
        else if(adj_list[a].find(b) != adj_list[a].end()){
             check = true;
        }

        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}