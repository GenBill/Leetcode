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

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (r - 1 > l) {
            int m = (l + r) / 2;
            if (nums[m] <= nums[r]) r--;
            else l = m;
        }
        return nums[l]<nums[r]?nums[l]:nums[r];
    }
};
