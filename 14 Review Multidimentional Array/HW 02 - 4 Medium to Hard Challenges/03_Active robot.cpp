#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> nums(N, vector<int>(M, 0));
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int K;
    cin >> K;

    int nr = 0;
    int nc = 0;

    while(K--){
        int dir, steps;
        cin >> dir >> steps;
        dir--;


        nr = (nr + dr[dir] * steps) % N;
        if(nr < 0) nr += N;
        nc = (nc + dc[dir] * steps) % M;
        if(nc < 0) nc += M;


        cout << nr << ", " << nc << endl;
    }
}