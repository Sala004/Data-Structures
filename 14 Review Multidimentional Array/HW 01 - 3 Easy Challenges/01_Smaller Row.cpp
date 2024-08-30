#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M;
    vector<vector<int>> nums(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> nums[i][j];
        }
    }

    cin >> Q;    
    while(Q--){
        int r1, r2;
        cin >> r1 >> r2;
        r1--, r2--;
        bool is_smaller = true;

        if(r1 < 1 || r1 > N || r2 < 1 || r2 > N) {
            cerr << "Row indices out of bounds." << endl;
            continue;
        }

        for(int i = 0; i < M; i++){
            if(nums[r1][i] >= nums[r2][i]){
                is_smaller = false;
                break;
            }
        }

        if(is_smaller){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}