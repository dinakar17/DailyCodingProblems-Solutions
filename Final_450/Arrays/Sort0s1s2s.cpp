#include<bits/stdc++.h>
using namespace std;

/*
Story: start pointer belongs to number 0
end pointer belongs to number 2
mid pointer belongs to number 1

mid is the one which is actually traversing through the array
if it encounters 0 it'll swap it with start++
if it encounter 2 it'll swap it with end--
if it encounter 1 it just moves on...

In simple words, we're building two arrays from the start and end which results in building an array in the middle implicitly.
*/
void sort0s(vector<int>& nums){
  int n = nums.size();
  int mid = 0, start = 0, end = n-1;
  while(mid <= end){
    if(nums[mid] == 2) swap(nums[mid], nums[end--]);
    else if(nums[mid] == 1) mid++;
    else if(nums[mid] == 0) swap(nums[start++], nums[mid++]);
  }
}

int main(){
    vector<int> nums = {1, 0, 0};
    sort0s(nums);
    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    return 0;
}