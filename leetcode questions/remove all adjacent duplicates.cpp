#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        int sizee = s.size();
        for (int i = sizee - 1; i >= 0; i--) {
            char c = s[i];
            if (!st.empty() && c == st.top()) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};