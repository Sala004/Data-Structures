#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string big, string small){
    int lenBig = big.size();
    int lenSmall = small.size();

    int j = 0;
    for(int i = 0; i < lenBig; i++){
        if(big[i] == small[j]){
            j++;
        }

        if(j == lenSmall) return true;
    } 

    return false;
}

int main(){
    string big, small;
    cin >> big >> small;

    cout << isSubsequence(big, small);
}