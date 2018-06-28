#include <iostream>
#include <vector>

using namespace std;

vector<int> computeProductArrWithDivisionOp(vector<int>& arr) {

    vector<int> prodArr(arr.size());
    int cummProd = 1;
    for(int i=0;i<arr.size();i++) {
        cummProd *= arr[i];
    }

    for(int i=0;i<arr.size();i++) {
        prodArr[i] = (int) cummProd / arr[i];
    }
    return prodArr;

}

/**
This approach doesn't use the division operator.
This approach still works if an element is 0.
**/
vector<int> computeProductArr(vector<int>& arr) {

    //Make a new product array
    vector<int> prodArr(arr.size());
    int cummProd = 1;
    for(int i=arr.size()-1;i>=0;i--) {
        prodArr[i] = cummProd * arr[i];
        cummProd *= arr[i];
    }

    //The prodArr from the right to left
    cout << "The cummulative product array from right to left" << endl;
    for(int i=0;i<prodArr.size();i++) {
        cout << prodArr[i] << " ";
    }
    cout << endl;

    cummProd = 1;
    for(int i=0;i<arr.size()-1;i++) {
        prodArr[i] = prodArr[i+1] * cummProd;
        cummProd *= arr[i];
    }
    prodArr[arr.size()-1] = cummProd;

    return prodArr;
}


int main() {

    int N,num;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++) {
        cin >> num;
        arr.push_back(num);
    }
    vector<int> prodArr = computeProductArr(arr);
    for(int i=0;i<N;i++) {
        cout << prodArr[i] << " ";
    }
    cout << endl;

}
