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

    bool put(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < table_size; i++){
            if(!table[idx] || table[idx] == deleted){
                table[idx] = new PhoneEntry(phone);
                return true;
            }
            else if(table[idx]->name == phone.name){
                table[idx]->phone_number = phone.phone_number; //update
                return true;
            }
            idx = (idx + 1) % table_size;
        }
        return false; //can't insert. full table
    }

    bool remove(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        for(int i = 0; i < table_size; i++){
            if(!table[idx]){
                break; //empty
            }
            if(table[idx] != deleted && table[idx]->name == phone.name){
                delete table[idx];
                table[idx] = deleted;
                return true;
            }

            idx = (idx + 1) % table_size; //move next
        }

        return false;
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

    cout << table.remove(PhoneEntry("ali","")) << endl;
    cout << table.remove(PhoneEntry("smith","")) << endl;
    cout << table.remove(PhoneEntry("john","")) << endl;

    table.print_all();

}