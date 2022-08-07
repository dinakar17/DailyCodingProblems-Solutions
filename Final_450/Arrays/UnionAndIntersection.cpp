#include <bits/stdc++.h>
using namespace std;

vector<int> Union(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (nums1[i] < nums2[j])
        {
            result.push_back(nums1[i++]);
        }
        else if(nums1[i] > nums2[j]) result.push_back(nums2[j++]);
        else if(nums1[i] == nums2[j]){ result.push_back(nums1[i++]); j++; }
    }
    while(i < n) result.push_back(nums1[i++]);
    while(j < m) result.push_back(nums2[j++]);
    return result;
}

vector<int> Intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (nums1[i] < nums2[j]) i++;
        else if(nums1[i] > nums2[j]) j++;
        else if(nums1[i] == nums2[j]){ result.push_back(nums1[i++]); j++; }
    }
    return result;
}


int main(){
    vector<int> result;
    vector<int> nums1 = {1, 2, 4, 5, 7};
    vector<int> nums2 = {2, 3, 4, 9, 10};
    result = Intersection(nums1, nums2);
    for(int i : result) cout << i << " ";
    return 0;
}