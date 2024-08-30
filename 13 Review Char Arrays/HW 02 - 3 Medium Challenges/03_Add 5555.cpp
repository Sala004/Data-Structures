#include <iostream>
using namespace std;
string Add5555(string num){
    string AddEnd = "5555";
    int len = num.size();
    int carry = 0;

    if(len > 4) {
        AddEnd = string(len - 4, '0') + AddEnd;
    }

    for(int i = len - 1; i >= 0; i--){
        int sum = (num[i] - '0') + (AddEnd[i] - '0') + carry;
        num[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if(carry > 0){
        num = char(carry + '0') + num;
    }

    return num;
}

int main(){
    string num;
    cin >> num;

    cout << Add5555(num);
}