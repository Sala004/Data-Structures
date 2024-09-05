#include <iostream>
#include <vector>
#include <cstring> //memset
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	bool isLeaf { };

public:
	trie() {
		memset(child, 0, sizeof(child));
	}

	void insert(string str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	bool word_exist(string str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return false;	
			cur = cur->child[ch];
		}
		return cur->isLeaf;
	}

	bool word_exist_with_1_change(string str) {
		// Brute force all possible 1-char change and search for it
		// O(L * 26 * L)
		for (int i = 0; i < (int) str.size(); ++i) {
			char cpy = str[i];
			for (char ch = 'a'; ch <= 'z'; ch++) {
				if (ch == cpy)	
					continue;
				str[i] = ch;
				if (word_exist(str))
					return true;
			}
			str[i] = cpy;	// copy back
		}
		return false;
	}
};

class MagicDictionary {
public:
    trie tree;

	MagicDictionary() {
        
	}

	void buildDict(vector<string> dictionary) {
		for (int i = 0; i < (int) dictionary.size(); ++i) {
			tree.insert(dictionary[i]);
		}

	}

	bool search(string str) {
		return tree.word_exist_with_1_change(str);
	}
};

int main(){
    
}