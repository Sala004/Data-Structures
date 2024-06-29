// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to){
    graph[from].push_back(to);
}

class Solution {
    struct node{
        int r, c;
    };

    int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

    bool isValid(int row, int col, vector<vector<int>> & Matrix){
        if(row < 0 || row >= Matrix.size()){
            return false;
        }
        if(col < 0 || col >= Matrix[0].size()){
            return false;
        }
        return true;
    }

    pair<vector<node>, int> neighbours(int r, int c, vector<vector<int>> &matrix){
        vector<node> edges;
        int indegree = 0;
        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(!isValid(nr, nc, matrix)){
                continue;
            }
            if(matrix[r][c] < matrix[nr][nc]){
                edges.push_back({nr, nc});
            }
            else if(matrix[r][c] > matrix[nr][nc]){
                ++indegree;
            }
        }
        return {edges, indegree};
    }

public:
	int longestIncreasingPath(vector<vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> indegree(rows, vector<int>(cols));	// rows x columns
        queue <node> ready;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                indegree[r][c] = neighbours(r, c, matrix).second;

                if(indegree[r][c] == 0){
                    ready.push({r, c});
                }
            }
        }
    }

};

int main(){

}