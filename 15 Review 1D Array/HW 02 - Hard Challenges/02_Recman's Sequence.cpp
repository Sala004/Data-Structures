#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_SIZE = 201; 
    vector<int> visited(10 * MAX_SIZE, 0); 
    vector<int> seq(MAX_SIZE, 0); 
    seq[0] = 0;
    visited[0] = 1;
    
    int indx;
    cin >> indx;
    
    for(int i = 1; i < MAX_SIZE; i++){
        int nextVal = seq[i - 1] - (i - 1) - 1;
        if(nextVal < 0 || visited[nextVal]){
            nextVal = seq[i - 1] + (i - 1) + 1;
        }

        seq[i] = nextVal;
        visited[nextVal]++;
    }
    
    cout << seq[indx];
}
