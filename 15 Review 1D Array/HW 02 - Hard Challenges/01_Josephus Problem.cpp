#include <iostream>
#include <vector>
using namespace std;
void findWinner(int n, int k){
    vector<int> killed(n, 0);
    int last_position = 0;
    int still_alive = n;
    for(int i = 0; i < n; i++){
        int curr_k = (k % still_alive == 0) ? still_alive : k % still_alive;

        int step = 0;
        while(step < k){
            if(!killed[last_position]) {
                step++;
            }
            if(step < k){
                last_position = (last_position + 1) % n;
            }
            
        }

        killed[last_position] = 1;
        cout << last_position + 1 << " ";

    }

    cout << endl;
}

int main(){
    findWinner(41, 2);
}