#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

/**
Can do this in O(N) if we use a hash
space complexity is also O(N)
**/
int findFirstMissingPositiveInt(vector<int>& arr) {
    unordered_set <int> hash_map;
    for(int i=0;i<arr.size();i++) {
        hash_map.insert(arr[i]);
    }
    
    for(int i=1;i<hash_map.size();i++) {
        auto found = hash_map.find(i);
        if(found == hash_map.end()) {
            return i;
        }
    }
    return hash_map.size();
}

void printArray(vector<int>& arr) {
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int betterFindFirstMissingPositiveInt(vector<int>& arr) {
    int negIndEnd = 0;
    for(int i=0;i<arr.size();i++) {
        if(arr[i]<=0) {
            swap(arr[i], arr[negIndEnd]);
            negIndEnd++;
        }
    }

    printArray(arr);

    //negIndEnd is the 1st index with positive value
    // If all negative values in the array
    if(negIndEnd == arr.size()) return 1;

    int ind = negIndEnd;
    int tmp;
    for(int i=ind;i<arr.size();i++) {
        // value is in bounds of arr size and is still positive
        tmp = abs(arr[i])+ind-1;
        if( (tmp < arr.size()) && (arr[tmp] > 0) ) { 
            arr[tmp] *= -1;    
        }
    }

    printArray(arr);

    for(int i=1;i<arr.size();i++) {
        if(arr[i+ind-1] > 0) { // index value doesnt exist
            return i; 
        }
    }
    return arr.size()-ind+1;
}

int main() {
    int N,num;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++) {
        cin >> num;
        arr.push_back(num);
    }
    // return the first positive (non-zero) integer
    cout << "The first positive missing integer is:" << endl;
    cout << findFirstMissingPositiveInt(arr) << endl;
    cout << betterFindFirstMissingPositiveInt(arr) << endl;
}