#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

//problem 1
bool isIncreasing(int arr[], int size){
    for(int i = 1; i < size; i++){
        if(arr[i] < arr[i - 1]){
            return false;
        }
    }
    return true;
}

//problem 2
void Replace(int arr[], int size){
    int min = INT_MAX;
    int max = -100000;

    for(int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }

        if(arr[i] < min){
            min = arr[i];
        }
    }

    //replace

    for(int i = 0; i < size; i++){
        if(arr[i] == min){
            arr[i] = max;
        }

        if(arr[i] == max){
            arr[i] = min;
        }
    }
}

//Problem 3
void UniqueNumbersOrdered(int arr[], int size){
    cout << arr[0] << " ";
    for(int i = 1; i < size; i++){
        if(arr[i] != arr[i - 1]){
            cout << arr[i] << " ";
        }
    }
}

//Problem 4
bool isPlindrome(int arr[], int size){
    int start = 0;
    int end = size - 1;

    while(start < end){
        if(arr[end] != arr[start]){
            return false;
        }

        start++;
        end--;
    }

    return true;
}

//Problem 5
int smallestPair(int arr[], int size){
    int min = INT_MAX;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            int temp = arr[i] + arr[j] + j - i;
            if(temp < min){
                min = temp;
            }
        }
    }

    return min;
}


//Problem 6
int Search(int arr[], int size, int val){
    for(int i = size - 1; i >= 0; i--){
        if(arr[i] == val){
            return i;
        }
    }

    return -1;
}

//Problem 7
void FindMostFrequent(int arr[], int size){
    int repeated[801] {0};
    for(int i = 0; i < size; i++){
        repeated[arr[i] + 500]++;
    }

    int max = -1000;
    int pos = 0;
    for(int i = 0; i < 801; i++){
        if(repeated[i] > max){
            max = repeated[i];
            pos = i;
        }
    }

    cout << pos - 500 << " repeated " << max << " times";
}

//Problem 8
void DigitsFrequency(int arr[], int size){
    int frequency[10];

    for(int i = 0; i < size; i++){

        if(arr[i] == 0){
            frequency[0]++;
        }

        int digit = 0;
        int temp = arr[i];

        while(temp){
            digit = temp % 10;
            frequency[digit]++;
            temp /= 10;
        }
    }

    for(int i = 0; i < 10; i++){
        cout << i << " " << frequency[i] << endl;
    }
}


//Problem 9
void Find3Minimum(int arr[], int size){
    int min[3];

    for(int i = 0; i < size; i++){

        int maxPos;
        if(i < 3){
            min[i] = arr[i];
        }
        else{
            maxPos = 0;
            for(int j = 1; j < 3; j++){

                if(min[maxPos] < min[j]){
                    maxPos = j; 
                }
            }

            if(arr[i] < min[maxPos]){
                min[maxPos] = arr[i];
            }
        }

        
    }

    sort(min, min+3);

    for(int i = 0; i < 3; i++){
        cout << min[i] << " ";
    }
}

//Problem 10
void uniqueNumbersUnordered(int arr[], int size){
    //1 5 5 2 5 7 2 3 3 3 5 2 7
    int vis[501] {0};
    for(int i = 0; i < size; i++){
        if(!vis[arr[i]]){
            cout << arr[i] << " ";
        }
        vis[arr[i]] = 1;
    }

}

//Problem 11
void SortNumbers(int arr[], int size){
    int freq[501] {0};
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }

    for(int i = 0; i < 501; i++){
        while(freq[i]--){
            cout << i << " ";
        }
    }
}

int main(){
    int size;
    cin >> size;
    int arr[200];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    SortNumbers(arr, size);
}