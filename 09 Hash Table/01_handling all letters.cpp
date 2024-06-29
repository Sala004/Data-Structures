#include <iostream>
#include <vector>
using namespace std;

int hash_string(string str, int n){
    int base = 2 * 26 * 10;
    long long nn = n;
    long long sum = 0;
    for(int i = 0; i < (int) str.size(); i++){
        int value = 0;
        if(islower(str[i])){
            value = str[i] - 'a';
        }
        else if(isupper(str[i])){
            value = 26 + str[i] - 'A';
        }
        else if(isdigit(str[i])){
            value = 26 + 10 + str[i] - '0';
        }
        sum = (sum * base + value) % nn;
    }
    return sum;

}

struct PhoneEntry {
    const static int INTERNAL_LIMIT = 65407;
    string name;
    string phoneNumber;
    int hash(){
        return hash_string(name, INTERNAL_LIMIT);
    }

    PhoneEntry (string name,string phoneNumber):
        name(name), phoneNumber(phoneNumber){
    }
};

class PhoneHashTable{
private:
    int table_size;
    vector<vector<PhoneEntry>> table;

public:
    PhoneHashTable(int table_size):
        table_size(table_size)
    { table.resize(table_size); }

    void put(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < (int) table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                table[idx][i] = phone;  //exists -> update
                return;
            }
        }
        table[idx].push_back(phone);
    }

    bool get(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < (int) table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                phone = table[idx][i];
                return true;
            }
        }
        return false;
    }

    bool remove(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < (int) table[idx].size(); i++){
            if(table[idx][i].name == phone.name){

                // Swap with last and remove last in O(1)
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                return true;

            }
        }
        return false;
    }

    void print_all(){
        for(int hash = 0; hash < table_size; hash++){
            if(table[hash].size() == 0){
                continue;
            }

            cout << "Hash " << hash << ": ";
            for(int i = 0; i < (int) table[hash].size(); i++){
                cout << table[hash][i].name << ", " << table[hash][i].phoneNumber << " ";
            }
            cout << endl;
        }
    }
};



int main(){
    PhoneHashTable table(3);
    table.put(PhoneEntry("Salah", "01023068214"));
    table.put(PhoneEntry("Mom", "01025000637"));
    table.put(PhoneEntry("Dad", "01065035089"));

    table.print_all();
}