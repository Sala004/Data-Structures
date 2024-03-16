#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int color[120];

    bool DFS(int u, int col, vector<vector<int>>& adj) {
        color[u] = col;
        for (int v : adj[u]) {
            if(color[v] == -1){
                if(DFS(v, !col, adj) == false){
                    return false;
                }
            }
            else if(color[v] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i < 120; ++i) {
            color[i] = -1;
        }
        for(int i = 0; i < (int)graph.size(); i++){
            if(color[i] == -1){
                if (DFS(i, 0, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    // Example graph
    vector<vector<int>> graph = {
        {1, 2, 3, 4},
        {0, 3, 4},
        {0, 3}, 
        {0, 1, 2, 4}, 
        {0, 1, 3}
    };

    if (sol.isBipartite(graph)) {
        cout << "Graph is bipartite" << endl;
    } else {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}
