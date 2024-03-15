#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m, u, v;
const int N = 1e5;
vector <int> adj[N];
bool vis[N]; 

void DFS(int count){
    stack <int> stk;
    stk.push(count);
    vis[count] = true;
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        cout << "visiting: " << u << endl;
        for(int v : adj[u]){
            if(!vis[v]){
                stk.push(v);
                vis[v] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    int start;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        start = u;
    }
    DFS(start);
}