#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;

    int num = 0;
    for(int i = 0; i < str.size(); i++){
        num = num * 10 + (str[i] - '0');
    }

    cout << num << endl;
    cout << num * 3 << endl;
}