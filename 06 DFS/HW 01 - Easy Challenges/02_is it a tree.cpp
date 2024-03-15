#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int n, m, u, v;
vector <int> adj[N];
bool vis[N];

bool isCyclic(int u, int p){
    vis[u] = true;
    for(int v : adj[u]){
        if(vis[v] && v != p){
           return true;
        }
        else if(!vis[v]){
            if(isCyclic(v, u)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    int start;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        start = u;
    }

    string result = m == n - 1 && !isCyclic(start, -1)? "YES" : "NO";
    cout << result;
    
    return 0;
}