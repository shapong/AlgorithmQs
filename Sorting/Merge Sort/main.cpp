#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    for(int i=0;i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeInPlaceAttempt(vector<int>& arr, int low, int high) {

    int mid = ((high-low) / 2) + low;

    int k = mid+1, i = low, j = i+1;
    cout << "Low " << low << endl;
    cout << "High " << high << endl;
    cout << "mid " << mid << endl;
    int temp;

    if (k == high) {
        if(arr[i] > arr[j]) swap(arr[i], arr[j]);
    }
    while(j <= high) {
        i = j-1;
        temp = arr[j];
        if(arr[k] < temp && arr[k] > arr[i]) {
            while (arr[k] < temp && arr[k] > arr[i]) { // K is between I and J
                //swapping with j and inc j
                cout << "Swapping " << arr[k] << " with " << arr[j] << " because " << arr[k] << " is in [" << arr[i] << "," << temp << "]" << endl;
                swap(arr[k], arr[j]);
                printArray(arr);
                j++;
                if(arr[k+1] < temp && arr[k+1] > arr[i] && ((k+1) <= high) )  {
                    k++; continue;
                }
                break;
            }
        } else {
            j = k; k++;
        }
        // printArray(arr);
    }
    cout << "done "; printArray(arr);
    return;
}

void merge(vector<int>& arr, int low , int high) {

int sizeOfArr = (high-low)/2;

int mid = ((high-low) / 2 )+ low;

int* leftCopy = new int[mid - low + 1];
int* rightCopy = new int[high - mid];

int ind = 0;
for(int i=low;i<=mid;i++) {
    leftCopy[ind] = arr[i]; ind++;
}

ind = 0;
for(int i=mid+1;i<=high;i++) {
    rightCopy[ind] = arr[i]; ind++;
}

for() {
    
}

}

void merge_sort(vector<int>& arr, int low , int high) {

    if(low==high) return;

    int mid = ((high-low) / 2 )+ low;

    merge_sort(arr, low, mid);

    merge_sort(arr, mid+1, high);
    
    merge(arr, low, high);

    return;

}
//1 7 4 6 5
int main() {

    int N;
    cin >> N;

    int num;
    vector<int> arr;

    for(int i=0;i<N;i++) {
        cin >> num;
        arr.push_back(num);
    }

    merge_sort(arr,0,arr.size()-1);

    for(int i=0;i<N;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}