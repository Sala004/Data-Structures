#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
 int strStr(string haystack, string needle) {
    int needsize = needle.size();
    for(int i = 0; i < haystack.size(); i++){
        if (needle == haystack.substr(i, needsize)) {
            return i;
        }
    }
    return -1;
    }
};