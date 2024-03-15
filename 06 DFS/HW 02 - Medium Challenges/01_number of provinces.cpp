#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void DFS(int u, vector<vector<int>>& adj, bool vis[]) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                DFS(v, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); 
        
        //convert adjacency matrix to list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        bool vis[250] = {false}; 
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                DFS(i, adj, vis);
            }
        }
        return cnt;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,11}};
    cout << sol.findCircleNum(isConnected);
}