#include <iostream>
#include <map>
#include <vector>
using namespace std;

class trie{
private:
    trie* child[26];
    bool is_leaf;
    trie* root;

public:
    trie() {
        is_leaf = false;
        root = this;
    }

    void insert(const vector<string> path){
        trie* node =  this;

        for(int index = 0; index < path.size(); index++){
            if(!node->child.count(path[index])){
                node->child[path[index]] = new trie();
            }

            node = node->child[path[index]];
        }

        node->is_leaf = true;
    }

    void DisplayAllContent(){
        
    }
};