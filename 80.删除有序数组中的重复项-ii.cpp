#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)return nums.size();
        short index = 1;
        for(short i = 2; i < nums.size(); i++){
            if(nums[i] != nums[index-1]){
                nums[++index] = nums[i];
            }
        }
        return index+1;
    }
};
// @lc code=end

// Another Solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)return nums.size();
        bool flag = 0;
        short now = nums[0];
        short Ret = nums.size();
        for(short i=1; i<Ret; i++){
            if(nums[i]==now){
                if(flag){
                    Ret--;
                    nums.erase(nums.begin()+i--);
                }else flag = 1;
            }else{
                now = nums[i];
                flag = 0;
            }
        }
        return Ret;
    }
};
