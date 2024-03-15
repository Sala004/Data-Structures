#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    stack<int> result;
    const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;
    int vis[5000];
    int visi[5000];
private:
bool isCyclic(int u, vector<vector<int>>& adj){
    vis[u] = IN_PROGRESS;
    for(int v : adj[u]){
        if(vis[v] == NOT_VISITED){
            if(isCyclic(v, adj)) {
                return true;
            }
        }
        else if(vis[v] == IN_PROGRESS){
            return true;
        }
    }
    vis[u] = VISITED;
    return false;
}

void DFS(int u, vector<vector<int>>& adj){
    visi[u] = VISITED;
    for(int v : adj[u]){
        if(visi[v] == NOT_VISITED){
            DFS(v, adj);
        }
    }
    result.push(u);
}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(5000);
    for (auto& prerequisite : prerequisites) {
        adj[prerequisite[1]].push_back(prerequisite[0]);
    }
    for(int u = 0; u < numCourses; u++) {
        if(vis[u] == NOT_VISITED){
            if(isCyclic(u, adj)){ 
                return {};
            }
            else{
                DFS(u, adj);
            }
        }
    }

    vector<int> ans;
    while(!result.empty()){
        ans.push_back(result.top());
        result.pop();
    }
    return ans;
}

};

int main() {
    int numCourses = 4; 
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    Solution sol;
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    for (int v : result) {
        cout << v << " ";
    }
    return 0;
}