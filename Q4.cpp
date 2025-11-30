#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n = 6;

    vector<vector<pair<int,int>>> adj(n);

    adj[0] = {{1,4},{2,1}};
    adj[1] = {{3,1}};
    adj[2] = {{1,2},{4,5}};
    adj[3] = {{5,3}};
    adj[4] = {{5,2}};
    adj[5] = {};

    vector<int> dist(n, 1e9);
    dist[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;

        for(auto &p : adj[u]){
            int v=p.first, w=p.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node 0:\n";
    for(int i=0;i<n;i++)
        cout << "0 -> " << i << " = " << dist[i] << "\n";
}
