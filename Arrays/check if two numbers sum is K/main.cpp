#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
Will skip writing the code for the naive approach which is to 
Iterate through the array and for each A[i] find if K - A[i] exists.

This approach uses a hash map. And maps every value in the array.
Only does this in 1 pass.
**/
bool findSumK(vector<int>& arr, int K) {
    unordered_set <int> hash_map;
    for(int i=0;i<arr.size();i++) {
        auto found = hash_map.find(K - arr[i]);
        if( found == hash_map.end() ) {
            hash_map.insert({arr[i], true});
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int N,num,K;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++) {
        cin >> num;
        arr.push_back(num);
    }
    cout << "Enter sum to look for" << endl;
    cin >> K;
    (findSumK(arr, K))? cout << "Yes" << endl : cout << "No" << endl;
}