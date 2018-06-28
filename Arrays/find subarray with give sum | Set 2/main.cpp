#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
This approach only works also works for negative numbers

INPUT

3

5 -9 7
3

OUTPUT
YES
**/
bool findSubarryWithGivenSum(vector<int>& arr, int sum) {

    int sumEndingHere=0,start=0,i=0;
    unordered_map<int,int> hash_map;
    hash_map.insert(make_pair(0,-1));
    while(i < arr.size()) {
        sumEndingHere += arr[i];
        hash_map.insert(make_pair(sumEndingHere,i));
        if(hash_map.find(sumEndingHere - sum) != hash_map.end()) {
            cout << "Subarray from " << hash_map[sumEndingHere-sum]+1 << " to " << i << endl;
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int N,num,sum;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++) {
        cin >> num;
        arr.push_back(num);
    }
    cin >> sum;
    findSubarryWithGivenSum(arr,sum) ? cout << "Yes" : cout << "No"; 
    cout << endl;
}