#include <iostream>
#include <vector>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = 1;
    cout << u << " ";

    for(int v : adj[u])
        if(!vis[v]) DFS(v, adj, vis);
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

    vector<int> vis(n,0);

    cout << "DFS from node 0: ";
    DFS(0, adj, vis);
}
