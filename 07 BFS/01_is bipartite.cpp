#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int NOT_COLORED = 0, RED = 1, BLUE = 2;
const int N = 1e5, OO = 0x3f3f3f3f;
vector <int> adj[N];
int n, m, u, v;

int color[N];
bool isBipartite(int src){
    memset(color, NOT_COLORED, sizeof color);
    queue <int> q;
    color[src] = RED;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(color[v] == NOT_COLORED){
                color[v] = (color[u] == RED ? BLUE : RED);
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }

    return true;
    
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   cout << (isBipartite(0)? "YES" : "NO");
}