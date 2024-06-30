#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int count_unique_substring(string str){
    unordered_set <string> s;

    for(int start = 0; start < (int) str.size(); start++){
        for(int end = start; end < (int) str.size(); end++){
            s.insert(str.substr(start, end - start + 1));
        }
    }

    return s.size();
}

int main(){
    cout << count_unique_substring("aaaaa") << endl;
    cout << count_unique_substring("aaaba") << endl;
    cout << count_unique_substring("abcdef") << endl;
}