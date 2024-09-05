#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

class trie {
private:
    static const int MAX_CHAR = 26;
    trie* child[MAX_CHAR];
    bool is_leaf = false;

public: 
    trie() : is_leaf(false) {
        memset(child, 0, sizeof(child));
    }

    void insert(const string& str) {
        trie* node = this;
        for (char ch : str) {
            int curr = ch - 'a';
            if (node->child[curr] == nullptr) {
                node->child[curr] = new trie();
            }
            node = node->child[curr];
        }
        node->is_leaf = true;
    }

    string smallest_prefix(const string& str) {
        trie* node = this;
        string res = "";
        for (char ch : str) {
            int curr = ch - 'a';
            if (node->child[curr] == nullptr) {
                return str; 
            }
            res += ch;
            node = node->child[curr];
            if (node->is_leaf) {
                return res;
            }
        }
        return res;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie initial;
        for (const string& word : dictionary) {
            initial.insert(word);
        }

        istringstream stream(sentence);
        string word;
        string res = "";

        while (stream >> word) {
            if (!res.empty()) {
                res += " ";
            }
            res += initial.smallest_prefix(word);
        }

        return res;
    }
};

int main(){
    
}