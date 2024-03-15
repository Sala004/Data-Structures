#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;
    int vis[5000];
private: 
    bool isCyclic(int u, vector<vector<int>>& adj){
        vis[u] = IN_PROGRESS;
        for(int v : adj[u]){
            if(vis[v] == IN_PROGRESS){
                return true;
            }
            else if(vis[v] == NOT_VISITED ){
                if(isCyclic(v, adj)){
                    return true;
                }
            }
        }
        vis[u] = VISITED;   
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto& prerequisite : prerequisites) {
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }

    for(int u = 0; u < numCourses; u++){
        if(vis[u] == NOT_VISITED && isCyclic(u, adj)){
            return false;
        }
    }

    return true;

}
};