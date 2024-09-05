#include <iostream>
#include <map>
using namespace std;

class trie{
private:
    map<int, trie*> child;
    bool is_leaf = false;

public: 
    trie(){}

    void insert(string str){
        trie* node = this;

        for(int index = 0; index < str.size(); index++){
            int curr = str[index] - 'a';
            if(!node->child.count(curr)){
                node->child[curr] = new trie();
            }
            node = node->child[curr];
        }

        node->is_leaf = true;
    }

    bool word_exist(string str){
        trie* node = this;

        for(int index = 0; index < str.size(); index++){
            int curr = str[index] - 'a';
            if(!node->child.count(curr)){
                return false;
            }
            node = node->child[curr];
        }

        return node->is_leaf;
    }

};

int main(){
    trie test;

    test.insert("salah");
    test.insert("tamer");
    test.insert("abcd");
    test.insert("xyz");

    cout << test.word_exist("sala") << endl;
    cout << test.word_exist("xyz") << endl;
}