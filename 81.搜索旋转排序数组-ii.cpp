#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i]==target)return 1;
        return 0;
    }
};

// @lc code=end
class Solution {
public:
    bool mysearch(vector<int>& nums, int target, int i){
        int j = i+i<nums.size() ? i+i:nums.size();
        while(nums[i]<=target && target<=nums[j]){
            if(nums[i]==target)return 1;
            if(nums[j]==target)return 1;
            i = i+i<nums.size() ? i+i:nums.size();
            j = i+i<nums.size() ? i+i:nums.size();
        }
        if(i==nums.size()){
            if(nums[i]==target)return 1;
            else return 0;
        }
        return mysearch(nums, target, i+1);
    }
    bool simple_search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            if(nums[i]==target)return 1;
        return 0;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size()<100)return simple_search(nums,target);
        return mysearch(nums,target,1);
    }
};