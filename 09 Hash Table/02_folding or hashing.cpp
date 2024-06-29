#include <iostream>
#include <vector>
using namespace std;


int hash_string_upper_lower(string str, int n = 65407){
    int base = 2 * 26 * 10;
    long long nn = n;
    long long sum = 0;
    int value = 0;
    for(int i = 0; i < (int) str.size(); i++){
        if(islower(str[i])){
            value = str[i] - 'a';
        }

        else if(isupper(str[i])){
            value = 26 + str[i] - 'A';
        }

        else if(isdigit(str[i])){
            value = 26 * 10 + str[i] - '0';
        }

        sum = (sum * base + value) % nn; 
    }
    return sum;
}

int hash_string_folding(string str, int n = 65407){
    long long sum = 0;
    long long nn = n;
    for (int i = 0; i < (int)str.size(); i += 4)
    {
        string block = str.substr(i, 4);
        sum += hash_string_upper_lower(block);
        sum %= nn;
    }
    return sum;
}



int main(){
    cout << hash_string_folding("aabcdefgAxT334gfg");
}