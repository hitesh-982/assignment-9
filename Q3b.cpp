#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n = 5;

    int graph[5][5] = {
        {0,4,4,0,0},
        {4,0,2,5,0},
        {4,2,0,5,11},
        {0,5,5,0,2},
        {0,0,11,2,0}
    };

    vector<int> key(n, INT_MAX), parent(n,-1), used(n,0);
    key[0] = 0;

    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++)
            if(!used[j] && (u==-1 || key[j] < key[u])) u=j;

        used[u] = 1;

        for(int v=0; v<n; v++){
            if(graph[u][v] && !used[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST edges:\n";
    int total = 0;
    for(int i=1;i<n;i++){
        cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        total += key[i];
    }
    cout << "Total Weight = " << total << "\n";
}
