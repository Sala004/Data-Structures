#include <iostream>
#include <map>
#include <vector>
using namespace std;

class trie{
private:
    map<string, trie*> child;
    bool is_leaf;

public:
    trie() {}

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


    bool subpath_exist(const vector<string> &path){
        trie* node = this;

        for(int index = 0; index < path.size(); index++){
            if(!node->child.count(path[index])){
                return false;
            }

            node = node->child[path[index]];
        }

        return true;
    }
};

int main(){
    trie test;

    vector<string> path;

    //  insert

    path = {"home", "software", "eclipse"};
	test.insert(path);

	path = {"home", "software", "eclipse", "bin"};
	test.insert(path);

	path = {"home", "installed", "gnu"};
	test.insert(path);

    //check if exist

    path = {"home", "software"};
    cout << test.subpath_exist(path) << endl;

    path = {"home", "installed"};
    cout << test.subpath_exist(path) << endl; 


}