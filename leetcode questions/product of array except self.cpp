#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
       vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCount = count(nums.begin(), nums.end(), 0);
        if (zeroCount > 1) {
            return vector<int>(size(nums));
        }

        for (int c : nums) {
            if (c) {
                product *= c;
            }
        }

        for (int& c : nums) {
            if (zeroCount) {
                if (c == 0) {
                    c = product;
                }
                else {
                    c = 0;
                }
            }
            else {
                c = product / c;
            }
        }

        return nums;
    }
};