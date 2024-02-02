#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int n1, n2;
        for(int i = 0; i < size; i++){
            for (int j = i + 1; j < size; j++){
                if(nums[i] + nums[j] == target){
                    n1 = i;
                    n2 = j;
                }
            }
        }
        return {n1, n2};
    }
};