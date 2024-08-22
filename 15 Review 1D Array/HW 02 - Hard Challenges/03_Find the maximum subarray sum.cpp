#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Complexity: O(n^2)
int maxSum(vector<int> &nums, int k){
    int len = nums.size();
    if (len == 0 || k > len) return 0;

    int maxVal = INT_MIN;

    for(int i = 0; i < len - k + 1; i++){
        int sum = 0;
        for(int j = 0; j < k; j++){
            sum += nums[i + j];
        }
        maxVal = max(maxVal, sum);
    }

    return maxVal;
}

// Complexity: O(n)
int maxSumOptimized(vector<int> &nums, int k){
    int len = nums.size();
    if (len == 0 || k > len) return 0;

    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i];
    }

    int maxVal = sum;
    for(int i = k; i < len; i++){
        sum = sum - nums[i - k] + nums[i];
        maxVal = max(maxVal, sum);
    }

    return maxVal;
}

int main(){
    int k, n;
    cin >> k >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << maxSumOptimized(nums, k);

    return 0;
}
