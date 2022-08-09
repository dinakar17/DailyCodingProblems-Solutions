#include<bits/stdc++.h>
using namespace std;

int LongestIncreasingSubSequence(vector<int> nums){
    int n = nums.size();
    vector<int> freq(n, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]) freq[i] = max(1 + freq[j], freq[i]);
        }
    }
    return *max_element(freq.begin(), freq.end());
}

int main(){
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60 };
    cout << LongestIncreasingSubSequence(nums);
    return 0;
}