#include <iostream>
#include <vector>
using namespace std;

class Solution {

private:
    void capture(int r, int c, vector<vector<char>>& board) {
        int Rows = board.size();
        int Cols = board[0].size();
        if (r < 0 || c < 0 || r == Rows || c == Cols || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        capture(r + 1, c, board);
        capture(r - 1, c, board);
        capture(r, c + 1, board);
        capture(r, c - 1, board);
    }

public:
    void solve(vector<vector<char>>& board){
        int Rows = board.size();
        int Cols = board[0].size();
        for(int c = 0; c < Cols; c++){
            if(board[0][c] == 'O'){
                capture(0, c, board);
            }
            if(board[Rows - 1][c] == 'O'){
                capture(Rows - 1, c, board);
            }
        }

        for(int r = 0; r < Rows; r++){
            if(board[r][0] == 'O'){
                capture(r, 0, board);
            }
            if(board[r][Cols - 1] == 'O'){
                capture(r, Cols - 1, board);
            }
        }

        for(int r = 0; r < Rows; r++){
            for(int c = 0; c < Cols; c++){
                if(board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
                else if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }
    }

};
int main() {
    // Example board
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution sol;
    sol.solve(board);

    // Output the modified board
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}