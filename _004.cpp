#include <iostream>
#include <vector>
using namespace std;

    double singleMedian(vector<int>& nums){
        int L = nums.size();
        if(L%2)return nums[L];
        else return (nums[L]+nums[L-1])/2.0;
    }
    double doubleMedian(vector<int>& nums1, vector<int>& nums2){
        int L1 = nums1.size(), L2 = nums2.size();
        int L3 = L1 + L2;
        int target = L3/2;

        int i1 = 0, i2 = 0;
        while(i1+i2+1<target){
            while(nums1[i1]>nums2[i2]&&i1+i2<target&&i2+1<L2)i2++;
            while(nums1[i2]>nums2[i1]&&i1+i2<target&&i1+1<L1)i1++;
        }
        if(L3%2){
            return max(nums1[i1],nums2[i2]);
        }else{
            double s3 = (nums1[i1]+nums2[i2])/2;
            if(i1>0 && i2>0){
                double s1 = (nums1[i1-1]+nums1[i1])/2;
                double s2 = (nums1[i2-1]+nums1[i2])/2;
                if(s1>s2)return s1>s3?s1:s3;
                else return s2>s3?s2:s3;
            }else{
                if(i1>0){
                    double s1 = (nums1[i1-1]+nums1[i1])/2;
                    return s1>s3?s1:s3;
                }else{
                    double s2 = (nums1[i2-1]+nums1[i2])/2;
                    return s2>s3?s2:s3;
                }
                return s3;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int L1 = nums1.size(), L2 = nums2.size();
        if(L1==0||L2==0){
            return L2==0?singleMedian(nums1):singleMedian(nums2);
        }
        else{
            return doubleMedian(nums1, nums2);
        }
    }

void show_Vector(vector<int>& nums){
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    show_Vector(nums1);
    show_Vector(nums2);

    double Ret = findMedianSortedArrays(nums1,nums2);
    cout << Ret << endl;
    return 0;
}