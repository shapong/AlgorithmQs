#include <iostream>
#include <climits>
#include <vector>

using namespace std;
/**
This approach only works for postive numbers

Negative number case that does not works

INPUT

3

5 -9 7
3

OUTPUT
No

For handling negative numbers see find a subarray with give sum | set 2

**/
bool findSubarryWithGivenSum(vector<int>& arr, int sum) {

    int sumEndingHere=0,start=0,i=0;
    while(i < arr.size()) {
        sumEndingHere += arr[i];
        if(sumEndingHere == sum) {
            cout << "Subarrary from " << start << " to " << i << endl;
            return true;
        }
        if(sumEndingHere > sum) {
            while (sumEndingHere > sum) {
                sumEndingHere -= arr[start];
                start++;
                if(sumEndingHere == sum) {
                    cout << "Subarrary from " << start << " to " << i << endl;
                    return true;
                }
            }
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