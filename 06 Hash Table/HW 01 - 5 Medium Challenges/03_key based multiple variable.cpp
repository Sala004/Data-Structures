#include <iostream>
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

int hash_num(int num, int n = 65407){
    long long nn = n;
    return (num % nn + nn) % nn; 
}


struct someObject {
    const static int INTERNAL_LIMIT = 2147483647;
    string str1, str2;
    int num;

    int hash(){
        long long res = hash_string_upper_lower(str1 + str2, INTERNAL_LIMIT);
        res += hash_num(num, INTERNAL_LIMIT);
        return res % INTERNAL_LIMIT;
    }
};

int main(){
    someObject test;
    test.str1 = "Salah";
    test.str2 = "Tamer";
    test.num = 2004;
    cout << test.hash();
}