#include <iostream>
using namespace std;

bool isSubstring(string first, string second) {
    int lenF = first.size();
    int lenS = second.size();

    if (lenS > lenF) return false; 

    for (int i = 0; i <= lenF - lenS; i++) {
        int j = 0;
        while (j < lenS && first[i + j] == second[j]) {
            j++;
        }
        if (j == lenS) return true; 
    }

    return false;
}

int main() {
    string first, second;
    cin >> first >> second;

    cout << isSubstring(first, second);
}
