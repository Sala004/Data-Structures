#include <iostream>
#include <vector>
using namespace std;

int increasingSub(vector<int> &nums){
    int len = nums.size();
    if(len == 1) return 1;

    int totalCount = len;
    int count = 1;

    for(int i = 1; i < len; i++){
        if(nums[i] > nums[i - 1]){
            totalCount += count;
            count++;
        }
        else{
            count = 1;
        }
    }

    return totalCount;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << increasingSub(nums);

}