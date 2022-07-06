/*
This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order,
 write a function that calculates the maximum profit you could have made from buying and selling that stock "once".
You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/

#include<bits/stdc++.h>
using namespace std;

// Logic: Think locally, not globally  i.e., in the above example, consider the *ascending series's* that is,
// [9, 11] buy = 9, sell = 11 => profit = 2
// [8] buy = 9, sell = 8 => profit = 0
// [5, 7, 10] buy = 5, sell = 10 => profit = 5
// Note: Above variable "sell" is represented by nums[i]

int maxProfit(vector<int> nums){
    int n = nums.size();
    int buy = nums[0];
    int max_profit = 0;
    for(int i = 1; i < n; i++){
        if(nums[i] > buy) max_profit = max(max_profit, nums[i] - buy);
        else buy = nums[i];
    }
    return max_profit;
}