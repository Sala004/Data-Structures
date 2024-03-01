#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNextGreater(vector<int> &vec) {
	stack <int> stk;
	int len = vec.size();
	vector <int> result(len);
	for(int i = len - 1; i >= 0; i--){
		
		//check if element smaller than the top of the stack
		while(!stk.empty() && vec[i] >= stk.top()){
			stk.pop();
		}

		//if stack empty, no greater element exists, so it will return -1
		result[i] = stk.empty()? -1 : stk.top();

		//push current element onto stack
		stk.push(vec[i]);
	}

	return result;
}

int main() {
	int size;
	vector <int> vec;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int element;
		cin >> element;
		vec.push_back(element);
	}
	vector<int> result = findNextGreater(vec);
	for (auto c : result) {
		cout << c << " ";
	}
}