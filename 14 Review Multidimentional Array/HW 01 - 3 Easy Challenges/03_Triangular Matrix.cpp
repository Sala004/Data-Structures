#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> nums(N, vector<int>(N));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> nums[i][j];
        }
    }

    int sum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            sum += nums[i][j];
        }
    }

    cout << sum << " ";

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            sum += nums[i][j];
        }
    }

    cout << sum << " ";
}
