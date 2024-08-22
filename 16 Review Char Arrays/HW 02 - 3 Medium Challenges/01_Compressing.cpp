#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string str;
    cin >> str;
    str += '$'; // a dummy end charؤ

    char temp = str[0];
    int count = 1;

    for(int i = 1; i < str.size(); i++){
        if(str[i] != temp){
            cout << temp << to_string(count) << " ";
            count = 1;
            temp = str[i];
        }
        else{
            count++;
        }
    }
}