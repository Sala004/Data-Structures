#include <iostream>
using namespace std;

bool isSuffix(string first, string second){
    int lenF = first.size();
    int lenS = second.size();

    if(lenS > lenF) return false;
    int big_end = lenF - 1;
    int small_end = lenS - 1;
    
    for(int i = 0; i < lenS; i++){
        if(first[big_end--] != second[small_end--]) {
            return false;
        }
    }

    return true;
}

int main(){
    string first, second;
    cin >> first >> second;

    cout << isSuffix(first, second);
}