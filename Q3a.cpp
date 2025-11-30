#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u, v, w;
};

int findP(int x, vector<int>& parent){
    if(parent[x] == x) return x;
    return parent[x] = findP(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank){
    a = findP(a, parent);
    b = findP(b, parent);
    if(rank[a] < rank[b]) parent[a] = b;
    else if(rank[b] < rank[a]) parent[b] = a;
    else{
        parent[b] = a;
        rank[a]++;
    }
}

int main(){
    vector<Edge> edges = {
        {0,1,4}, {0,2,4}, {1,2,2},
        {1,3,5}, {2,3,5}, {2,4,11},
        {3,4,2}
    };

    int n = 5;
    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    cout << "Kruskal MST edges:\n";
    int total = 0;

    for(auto &e : edges){
        if(findP(e.u,parent) != findP(e.v,parent)){
            unite(e.u, e.v, parent, rank);
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
            total += e.w;
        }
    }

    cout << "Total Weight = " << total << "\n";
}
