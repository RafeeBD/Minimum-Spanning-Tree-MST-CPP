#include <bits/stdc++.h>

using namespace std;

int parent[100], r[100];

int makeSet(int node){
    parent[node] = node;
    r[node] = 0;
}

int findPar(int node){
    if(parent[node] == node) return node;
    return parent[node] = findPar(parent[node]);
}

void unionSet(int a, int b){
    a = findPar(a);
    b = findPar(b);
    if(a == b) return;
    if(r[a] > r[b]){
        parent[b] = a;
    } else if(r[a] == r[b]){
        parent[a] = b;
        r[b]++;
    } else parent[a] = b;
}

struct Edge{
    int x, y, weight, indx;
};

bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}

int main(){
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    vector <Edge> v;
    for(int i = 1 ; i <= edges ; i++){
        cout << "Enter 2 nodes and weight of edge number " << i << ": ";
        Edge e;
        cin >> e.x >> e.y >> e.weight;
        e.indx = i;
        v.push_back(e);
    }
    for(int i = 1 ; i <= nodes ; i++)
        makeSet(i);
    sort(v.begin(), v.end(), cmp);
    int totalCost_MinSpanTree = 0;
    for(auto [x, y, w, i] : v){
        if(findPar(x) == findPar(y)){
            continue;
        }
        unionSet(x, y);
        cout << "Edge taken: " << x << " " << y << endl;
        totalCost_MinSpanTree += w;
    }
    cout << "Total cost of tree: " << totalCost_MinSpanTree << endl;
}
/*
5 6
1 2 10
2 3 2
3 5 1
2 5 8
5 4 8
4 1 2
*/
