#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<vector<int>> adj(n); 
        
        // Building the adjacency list
        for(auto it : pre){
            adj[it[1]].push_back(it[0]); 
        }
        
        vector<int> indegree(n, 0); 
        // Calculating indegrees of all vertices
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        // Pushing vertices with 0 indegree into the queue
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        // Topological sorting using BFS
        while(!q.empty()){

            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            // Reducing indegrees of adjacent vertices and pushing 0 indegree vertices into the queue
            for(auto it : adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size() == n) return ans;
        else return {};
    }
};
