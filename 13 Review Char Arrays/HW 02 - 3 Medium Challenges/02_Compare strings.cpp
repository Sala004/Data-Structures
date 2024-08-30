#include <iostream>
#include <algorithm>
using namespace std;

bool isLessThan(string first, string second){
    int lenF = first.size();
    int lenS = second.size();
    int minLen = min(lenF, lenS);

    for(int i = 0; i < minLen; i++){
        if(first[i] != second[i]){
            return first[i] < second[i];
        }
    }

    return lenF <= lenS;
}

int main(){
    string first, second;
    cin >> first >> second;

    if(isLessThan(first, second)) cout << "YES";
    else cout << "NO"; 
}