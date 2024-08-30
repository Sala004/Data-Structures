#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false; 
    if (num == 2) return true;  
    if (num % 2 == 0) return false; 

    int sqrtNum = static_cast<int>(sqrt(num));
    for (int k = 3; k <= sqrtNum; k += 2) {
        if (num % k == 0) return false;
    }

    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> nums(N, vector<int>(M));
    vector<vector<int>> is_Prime(N, vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            cin >> nums[i][j];

            if(isPrime(nums[i][j])){
                is_Prime[i][j] = 1;
            }
            else{
                is_Prime[i][j] = 0;
            }
        }

        
    }

    int Q;
    cin >> Q;

    while(Q--){
        int i, j, r, c;
        cin >> i >> j >> r >> c;

        if(r + i > N || c + j > M) {
            cout << "Invalid Input!";
            return 0;
        }

        for (int row = i; row < i + r; row++) {
            for (int col = j; col < j + c; col++) {
                if (is_Prime[row][col]) {
                    cout << nums[row][col] << " ";
                }
            }
        }

        cout << endl;
    }


}