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
    double limit_load_factor;
    int total_elemnts = 0;
    vector<vector<PhoneEntry>> table;

public:
    PhoneHashTable(int table_size, double limit_load_factor):
        table_size(table_size), limit_load_factor(limit_load_factor)
    { table.resize(table_size); }

    void put(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < (int) table[idx].size(); i++){
            if(table[idx][i].name == phone.name){
                table[idx][i] = phone;  //exists -> update
                return;
            }
        }
        total_elemnts++;
        rehashing();
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
                --total_elemnts;
                rehashing();
                return true;

            }
        }
        return false;
    }

    void rehashing(){
        double curr_load_factor = (double) total_elemnts / table_size;
        cout << curr_load_factor << "\n";
        if(curr_load_factor < limit_load_factor){
            return;
        }

        PhoneHashTable new_table(2 * table_size, limit_load_factor);
        for(int hash = 0; hash < table_size; hash++){
            if(table[hash].size() == 0){
                continue;
            }

            for(int i = 0; i < (int) table[hash].size(); i++){
                new_table.put(table[hash][i]);
            }

        }

        table_size *= 2;
        table = new_table.table;
        print_all();

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
    PhoneHashTable table(5, 0.75);
    vector<PhoneEntry> entries = {
        {"Alice", "1234567890"},
        {"Bob", "0987654321"},
        {"Charlie", "5555555555"},
        {"David", "4444444444"},
        {"Eve", "3333333333"},
        {"Frank", "2222222222"},
        {"Grace", "1111111111"},
        {"Hank", "0000000000"}
    };

    for (const auto& entry : entries) {
        table.put(entry);
    }

    table.print_all();
}