#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.size();
    for (int i = 0; i < len; ++i) {
        if (i != 0 && str[i] != str[i - 1]) {
            cout << " ";
        }
        cout << str[i];
    }

    return 0;
}
