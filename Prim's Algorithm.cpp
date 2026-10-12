#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int nodes, edges;
vector <pii> adj[100];

void prim(int source){
    int dist[100], par[100], vis[100];
    for(int i = 0 ; i < 100 ; i++){
        dist[i] = INT_MAX/2;
        par[i] = i;
        vis[i] = false;
    }
    dist[source] = 0;
    priority_queue <pii, vector <pii>, greater<pii>> pq;
    pq.push({dist[source], source});
    while(pq.size()){
        auto [d, node] = pq.top();
        pq.pop();
        if(vis[node] == true) continue;
        vis[node] = true;
        dist[node] = d;
        for(auto [neighbour, w] : adj[node]){
            if(vis[neighbour] == false){
                if(dist[neighbour] > w)
                    par[neighbour] = node;
                pq.push({w, neighbour});
            }
        }
    }

    int cost = 0;
    for(int i = 1 ; i <= nodes ; i++){
        cout << "edge taken: " << i << " to " << par[i] << " weight: " << dist[i] << endl;
        cost += dist[i];
    }
    cout << "total weight is : " << cost << endl;

}

int main(){
    cout << "enter number of nodes: ";
    cin >> nodes;
    cout << "enter number of edges: ";
    cin >> edges;
    for(int i = 0 ; i < edges ; i++){
        cout << "enter two nodes and weight of edge " << i+1 << ": ";
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

   prim(1);
   return 0;
}


