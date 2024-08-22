#include <iostream>
using namespace std;

bool isPrefix(string first, string second){
    int lenF = first.size();
    int lenS = second.size();

    if(lenS > lenF) return false;

    for(int i = 0; i < lenS; i++){
        if(first[i] != second[i]){
            return false;
        }
    }

    return true;
}

int main(){
    string big_str, small_str;
    cin >> big_str >> small_str;

    cout << isPrefix(big_str, small_str);
}