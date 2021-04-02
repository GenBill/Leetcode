/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double singleMedian(vector<int>& nums) {
        int L = nums.size();
        int tar = L/2;
        if(L%2)return nums[tar];
        else return (nums[tar]+nums[tar-1])/2.0;
    }

    double doubleMedian0(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size(), L2 = nums2.size();
        int tar = (L1+L2)/2+1;
        int temp1 = 0, temp2 = 0;
        int i=0, j=0, index=0;
        while(index<tar&&i<L1&&j<L2){
            if(nums1[i]<nums2[j]){
                temp1 = temp2;
                temp2 = nums1[i];
                index++;
                i++;
            }else{
                temp1 = temp2;
                temp2 = nums2[j];
                index++;
                j++;
            }
        }
        if(i==L1){
            while(index<tar){
                temp1 = temp2;
                temp2 = nums2[j];
                index++;
                j++;
            }
        }else{
            while(index<tar){
                temp1 = temp2;
                temp2 = nums1[i];
                index++;
                i++;
            }
        }
        return (temp1+temp2)/2.0;
    }

    double doubleMedian1(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size(), L2 = nums2.size();
        int tar = (L1+L2)/2+1;
        int temp;
        int i=0, j=0, index=0;
        while(index<tar&&i<L1&&j<L2){
            if(nums1[i]<nums2[j]){
                temp = nums1[i];
                index++;
                i++;
            }else{
                temp = nums2[j];
                index++;
                j++;
            }
        }
        if(i==L1){
            while(index<tar){
                temp = nums2[j];
                index++;
                j++;
            }
        }else{
            while(index<tar){
                temp = nums1[i];
                index++;
                i++;
            }
        }
        return temp;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size(), L2 = nums2.size();
        if(L1==0||L2==0){
            if(L1)return singleMedian(nums1);
            else return singleMedian(nums2);
        }
        else{
            if((L1+L2)%2)return doubleMedian1(nums1, nums2);
            else return doubleMedian0(nums1, nums2);
        }
    }
};
// @lc code=end

