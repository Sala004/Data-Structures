#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> str;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                str.push(c);
            }
            else if(c == ')'){
                if(!str.empty() && str.top() == '('){
                    str.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == ']'){
                if(!str.empty() && str.top() == '['){
                    str.pop();
                }
                else{
                    return false;
                }
            }
            else if(c == '}'){
                if(!str.empty() && str.top() == '{'){
                    str.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!str.empty()){
            return false;
        }
        return true;
    }
};