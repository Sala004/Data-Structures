#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(int i = 0; i < s.size(); i++){
            int indx1 = s[i] - 'a';
            int indx2 = t[i] - 'a';
            arr1[indx1]++;
            arr2[indx2]++;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
};