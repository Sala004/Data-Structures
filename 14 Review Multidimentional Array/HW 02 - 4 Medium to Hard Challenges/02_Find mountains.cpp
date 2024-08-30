#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> nums(N, vector<int>(M));

    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> nums[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            bool isGreater = 1;
            for(int k = 0; k < 8; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr >= 0 && nr < N && nc >=0 && nc < M){
                    if(nums[nr][nc] >= nums[i][j]){
                        isGreater = 0;
                        break;
                    }
                }
            }

            if(isGreater){
                cout << nums[i][j] << " ";
            }
        }
    }
}