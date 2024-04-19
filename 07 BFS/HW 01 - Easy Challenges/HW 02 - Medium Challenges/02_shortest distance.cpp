#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


    int Row[4] = { 1, -1, 0, 0 };
    int Column[4] = { 0, 0, 1, -1 };

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0 || A[X][Y] == 0) {
            return -1;
        }

        queue<pair<int, int>> q;
        int** dis = new int* [N];
        bool** vis = new bool* [N];
        for (int i = 0; i < N; ++i) {
            dis[i] = new int[M];
            vis[i] = new bool[M];
        }

        //set all elements not visited
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                vis[i][j] = false;
            }
        }

        q.push(make_pair(0, 0));
        vis[0][0] = true;
        dis[0][0] = 0;

        while (!q.empty()) {
            pair<int, int> D = q.front();
            q.pop();

            if (D.first == X && D.second == Y) {
                return dis[X][Y];
            }
            for (int k = 0; k < 4; k++) {
                int r = D.first + Row[k];
                int c = D.second + Column[k];
                if (r >= 0 && r < N && c >= 0 && c < M) {
                    if (vis[r][c] == false && A[r][c] == 1) {
                        q.push(make_pair(r, c));
                        vis[r][c] = true;
                        dis[r][c] = dis[D.first][D.second] + 1;
                    }
                }
            }
        }

        // Free allocated memory
        for (int i = 0; i < N; ++i) {
            delete[] dis[i];
            delete[] vis[i];
        }
        delete[] dis;
        delete[] vis;

        return -1;
    }

int main() {
    int N, M, X, Y;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    cin >> X >> Y;
    cout << shortestDistance(N, M, A, X, Y);
}