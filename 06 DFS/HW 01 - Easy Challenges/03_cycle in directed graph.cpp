#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int n, m, u, v;
int NotVisited = 0, InProgress = 1, Visited = 2; 
vector <int> adj[N];
int vis[N];

bool isCyclic(int u){
    vis[u] = InProgress;
    for(int v : adj[u]){
        if(vis[v] == NotVisited){
            if(isCyclic(v)) {
                return true;
            }
        }
        else if(vis[v] == InProgress){
            return true;
        }
    }
    vis[u] = Visited;
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int u = 0; u < n; u++){
        if(vis[u] == NotVisited){
            if(isCyclic(u)){
                cout << "Cyclic";
                return 0;
            }
        }
    }
    cout << "Acyclic";
    return 0;
}