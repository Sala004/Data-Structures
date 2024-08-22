#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    string sub = "";
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        sub += str[i];
        if (i == len - 1 || str[i] != str[i + 1]) {
            cout << sub << " ";
            sub = "";
        }
    }

    return 0;
}
