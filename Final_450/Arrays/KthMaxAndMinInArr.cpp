#include <bits/stdc++.h>
using namespace std;

int KthMax(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    return nums[nums.size() - k];
}

int KthMin(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}

// use Heap
void heapify(vector<int> &nums, int n, int idx)
{
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int maxIdx = idx;
    if (l < n and nums[l] > nums[maxIdx])
        l = maxIdx;
    if (r < n and nums[r] > nums[maxIdx])
        r = maxIdx;

    if (maxIdx != idx)
    {
        swap(nums[idx], nums[maxIdx]);
        heapify(nums, n, maxIdx);
    }
}