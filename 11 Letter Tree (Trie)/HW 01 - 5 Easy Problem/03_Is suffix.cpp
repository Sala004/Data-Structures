#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class trie{
private: 
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool is_leaf = false;

public:
    trie(){
        memset(child, 0, sizeof(child));
    }

    void insert(string str){
        reverse(str.begin(), str.end());
        trie* node = this;
        
        for(int index = 0; index < str.size(); index++){
            int curr = str[index] - 'a';
            if(!node->child[curr]){
                node->child[curr] = new trie();
            }
            node = node->child[curr];
        }

        node->is_leaf = true;
    }

    bool is_suffix(string str) {
        reverse(str.begin(), str.end());
        trie* node = this;

        for(int index = 0; index < str.size(); index++){
            int curr = str[index] - 'a';
            if(!node->child[curr]){
                return false;
            }
            node = node->child[curr];
        }

        return true;
    }
};


int main(){
    trie test;
    test.insert("mohamed");
    cout << test.is_suffix("moha") << endl; //Output should be 0
    cout << test.is_suffix("med") << endl; // Output should be 1
}