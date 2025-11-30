#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int n){
    vector<int> vis(n,0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1,5};
    adj[4] = {2};
    adj[5] = {3};

    cout << "BFS from node 0: ";
    BFS(0, adj, n);
}
