#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> asteroidCollision(vector<int>& asteroids) {
       vector <int> vec;
       for (int curr : asteroids) { 
            while (!vec.empty() && curr < 0 && vec.back() > 0) {
                int diff = curr + vec.back();
                if (diff < 0) {
                   vec.pop_back();
                }
                else if (diff > 0) {
                       curr = 0;
                }
                else {
                    vec.pop_back();
                    curr = 0;
                }
            }
            if (curr) {
                vec.push_back(curr);
            }
       }
       return vec;
   }
};