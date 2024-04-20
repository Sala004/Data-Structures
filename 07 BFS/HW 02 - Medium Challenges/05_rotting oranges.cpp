#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;


class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Populate the queue with initial rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Perform BFS to rot adjacent fresh oranges
        while(!q.empty()){
            int size = q.size();
            bool flag = false; // Flag to track if any fresh oranges were rotten in this iteration

            // Process all oranges in the queue at this time step
            for(int i = 0; i < size; i++){
                pair<int, int> curr = q.front();
                q.pop();

                // Check adjacent cells
                for(int k = 0; k < 4; k++){
                    int r = curr.first + row[k];
                    int c = curr.second + col[k];
                    if(r >= 0 && c >= 0 && c < n && r < m){
                        if(grid[r][c] == 1){
                            grid[r][c] = 2; 
                            flag = true; 
                            q.push({r, c}); 
                        }
                    }
                }
            }
            if(flag) cnt++;
        }

        // Check if there are any fresh oranges left
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1; // If there are still fresh oranges left, return -1
            }
        }

        return cnt;
    }
};