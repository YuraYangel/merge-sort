#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr, int low, int high, int mid){
    int i = low, j = mid + 1, k = low;
    int massive [low + high];
    while (i <= mid and j <= high){
        if (arr[i] < arr[j]){
            massive[k] = arr[i];
            k ++;
            i ++;
        }
        else{
            massive[k] = arr[j];
            k ++;
            j ++;
        }
    }
    while (i <= mid){
        massive[k] = arr[i];
        k ++;
        i ++;
    }
    while (j <= high){
        massive[k] = arr[j];
        k ++;
        j ++;
    }
    for (int i = low; i < k; i ++){
        arr[i] = massive[i];
    }
}


void merge_sort(vector<int> &arr, int low, int high){
    int mid;
    if (low < high){
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }

}

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i ++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, N - 1);



    for (int i = 0; i < N; i ++){
        cout << arr[i] << " ";
    }
}