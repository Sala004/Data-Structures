#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int common_substrings(string str1, string str2){

    unordered_set <string> s1;
    for(int start = 0; start < (int) str1.size(); start++){
        for(int end = start; end < (int) str1.size(); end++){
            s1.insert(str1.substr(start, end - start + 1));
        }
    }

    unordered_set <string> s2;
    for(int start = 0; start < (int) str2.size(); start++){
        for(int end = start; end < (int) str2.size(); end++){
            s2.insert(str2.substr(start, end - start + 1));
        }
    }

    int cnt = 0;
    for(string element : s1){
        cnt += s2.count(element);
    }

    return cnt;
    
}

int main(){
    
    cout << common_substrings("aaab", "aa") << endl;
    cout << common_substrings("aaab", "ab") << endl;
}