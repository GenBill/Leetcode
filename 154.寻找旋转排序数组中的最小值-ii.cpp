#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=1; i<nums.size();i++){
            min = nums[i]<min ? nums[i]:min;
        }
        return min;
    }
};
// @lc code=end

