#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int max_idx = i;

    if(l < n && arr[l] > arr[max_idx]) max_idx = l;
    if(r < n && arr[r] > arr[max_idx]) max_idx = r;

    if(max_idx != i){
        swap(arr[i], arr[max_idx]);
        heapify(arr, n, max_idx);
    }
}

void heap_sort(int arr[], int n){
    // step 1 : heapify
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main(){
    int arr[] = {5, 4, 8, 1 ,3 ,8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // for(int i = 0; i < n/2; i++){
    //     heapify(arr, n, i);
    // }
    heap_sort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;

}