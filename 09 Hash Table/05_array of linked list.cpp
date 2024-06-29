#include <iostream>
#include <vector>
using namespace std;

int hash_string(string str, int n_ = 65407) {
	int base = 2 * 26 + 10;	
	long long n = n_;
	long long sum = 0;

	for (int i = 0; i < (int) str.size(); ++i) {
		
		int value = 0;
		if (islower(str[i]))
			value = str[i] - 'a';
		else if (isupper(str[i]))
			value = 26 + str[i] - 'A';
		else if (isdigit(str[i]))
			value = 26 + 26 + str[i] - '0';
		sum = sum * base + value;	
		sum %= n;
	}
	return sum % n;
}

struct PhoneEntry {
	const static int INTERNAL_LIMIT = 2147483647;
	string name;			// key
	string phone_number;	// data

	int hash() {
		return hash_string(name, INTERNAL_LIMIT);
	}

	PhoneEntry(string name, string phone_number) :
			name(name), phone_number(phone_number) {
	}
};

class PhoneHashTable{

private:
    struct Node{
        PhoneEntry item;
        Node* next;

        Node(PhoneEntry item) : item(item), next(nullptr) {}
    };
    int table_size;
    vector<Node*> table { };

public:
    PhoneHashTable(int table_size):
        table_size(table_size)
    {  table.resize(table_size); } 

    void put(PhoneEntry phone){
        int idx = phone.hash() % table_size;

        if(!table[idx]){
            table[idx] = new Node(phone);
        }
        else{
            // initializes head with the pointer to the first node (Node) in the linked list
            Node* head = table[idx];
            while(head->next){
                if(head->item.name == phone.name){
                    head->item = phone; //exist => update
                    return;
                }
                head = head->next;
            }

            //head now is tail
            if(head->item.name == phone.name){
                head->item = phone; //exist => update
            }
            else{
                head->next = new Node(phone);
            }
        }
        
    }

    void print_all(){
        for(int hash = 0; hash < table_size; hash++){
            if(!table[hash]){
                continue;
            }

            cout << "Hash " << hash << ": ";
            Node* curr = table[hash];
            while(curr){
                cout << curr->item.name << ", " << curr->item.phone_number << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};



int main(){
    PhoneHashTable table(3);
	table.put(PhoneEntry("mostafa", "604-401-120"));
	table.put(PhoneEntry("mostafa", "604-401-777"));	// update
	table.put(PhoneEntry("ali", "604-401-343"));
	table.put(PhoneEntry("ziad", "604-401-17"));
	table.put(PhoneEntry("hany", "604-401-758"));
	table.put(PhoneEntry("belal", "604-401-550"));
	table.put(PhoneEntry("john", "604-401-223"));

    table.print_all();
}