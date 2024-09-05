#include <iostream>
#include <cstring>
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
        trie* node = this;
        int len = str.size();

        for(int index = 0; index < len; index++){
            int curr = str[index] - 'a';
            if(node->child[curr] == nullptr){
                node->child[curr] = new trie();
            }

            node = node->child[curr];
        }

        node->is_leaf = true;
        
    }

    bool word_existing(string str){
        trie* node = this;
        int len = str.size();

        for(int index = 0; index < len; index++){
            int curr = str[index] - 'a';
            if(node->child[curr] == nullptr){
                return false;
            }

            node = node->child[curr];
        }

        return node->is_leaf;
    }
};

int main(){
    trie test;
    test.insert("apple");
    cout << test.word_existing("apple") << endl; //Output should be 1 (true)
    cout << test.word_existing("app") << endl; //Output should be 0 (false)
}