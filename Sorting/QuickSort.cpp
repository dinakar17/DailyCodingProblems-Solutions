#include<bits/stdc++.h>
using namespace std;


int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    for(int i = start; i <= end-1; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[end], arr[pIndex]);
    return pIndex;
}


void quickSort(int arr[], int start, int end){
    // base case
    if(start >= end) return;
    else{
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
    }
}

int main(){
    int arr[] = {11, 2, 3, 9, 2, 1, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}