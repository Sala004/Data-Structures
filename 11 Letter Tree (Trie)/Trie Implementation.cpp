#include <iostream>
#include <cstring>
using namespace std;

class trie{
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool is_leaf = 0;

public:
    trie() {
        memset(child, 0, sizeof(child));
    } 

    void insert(string str, int index = 0){
        if(index == str.size()) is_leaf = true;
        else{
            int curr = str[index] - 'a';
            if(child[curr] == 0){
                child[curr] = new trie();
            }

            child[curr]->insert(str, index + 1);
        }
    }

    bool prefix_exist(string str, int index = 0){
        if(index == str.size()) return true;

        int curr = str[index] - 'a';
        if(!child[curr]) return false;

        return child[curr]->insert(str, index + 1);
    }
};

int main(){

}