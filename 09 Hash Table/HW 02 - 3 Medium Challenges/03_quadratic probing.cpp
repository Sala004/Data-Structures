#include <iostream>
#include <vector>
using namespace std;

int hash_string(string str, int n = 65407){
    long long nn = n;
    long long sum = 0;
    for(int i = 0; i < (int) str.size(); i++){
        sum += (sum * 26 + str[i] - 'a') % nn;
    }
    return sum % nn;
}

struct PhoneEntry{
    const static int INTERNAL_LIMIT = 65407;
    string name;
    string phone_number;

    PhoneEntry(string name, string phone_number):
        name(name), phone_number(phone_number){}

    int hash(){
        return hash_string(name, INTERNAL_LIMIT);
    }
};

class PhoneHashTable{
private: 
    int table_size;
    vector<PhoneEntry*> table;
    PhoneEntry* deleted {};

public:
    PhoneHashTable(int table_size):
        table_size(table_size){
            table.resize(table_size);
            deleted = new PhoneEntry("", ""); //needs a destructor
    }

    void put(PhoneEntry phone){
        int idx = phone.hash() % table_size;
        int step = 0; int original_idx = idx;

        
        do {
            if(!table[idx] || table[idx] == deleted){
                table[idx] = new PhoneEntry(phone);
                return;
            }
            else if(table[idx]->name == phone.name){
                table[idx]->phone_number = phone.phone_number; 
                return;
            }
            step++;
            idx = (idx + step * step) % table_size;
        } while (idx != original_idx);
        
        rehashing();
        put(phone);

    }

    bool remove(PhoneEntry phone){
        int idx = phone.hash() % table_size;
        int original_idx = idx; int step = 0;

        do{
            if(!table[idx]){
                break; //empty
            }
            if(table[idx] != deleted && table[idx]->name == phone.name){
                delete table[idx];
                table[idx] = deleted;
                return true;
            }
            step++;
            idx = (idx + step * step) % table_size; //move next
        } while(idx != original_idx);

        return false;
    }

    void rehashing(){
        cout << "rehashing\n";
        PhoneHashTable new_table(2 * table_size);

        for(int hash = 0; hash < table_size; hash++){
            if(table[hash] == deleted || !table[hash]){
                continue;
            }

            new_table.put(*table[hash]);
        }

        table_size *= 2;
        table = new_table.table;
    }

    void print_all(){
        for(int hash = 0; hash < table_size; hash++){
            cout << hash << " ";
            if(table[hash] == deleted){
                cout << " X ";
            }
            else if(!table[hash]){
                cout << " E ";
            }
            else{
                cout << table[hash]->name << ", " << table[hash]->phone_number << " ";
            }
            cout << endl;
        }
        cout << "*************************\n";
    }

};

int main(){
    PhoneHashTable table(11);
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("mostafa", "604-401-777")); //update
	table.put(PhoneEntry("ali", "604-401-343"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("belal", "604-401-550"));
	table.put(PhoneEntry("john", "604-401-223"));

    table.print_all();

    table.remove(PhoneEntry("ali", ""));
    table.remove(PhoneEntry("john", ""));

    table.print_all();


}