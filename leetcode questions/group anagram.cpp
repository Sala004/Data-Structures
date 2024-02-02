#include<iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (auto str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        vector <vector<string>> result;
        for (const auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};