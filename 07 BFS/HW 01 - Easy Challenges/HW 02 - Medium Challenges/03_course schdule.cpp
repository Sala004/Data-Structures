#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        vector<int> adj[n]; 
        for(auto it : pre){
            adj[it[1]].push_back(it[0]); 
        }
        
        vector<int> indegree(n, 0); 
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue <int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector <int> ans;
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
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
