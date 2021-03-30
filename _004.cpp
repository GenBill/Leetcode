#include <iostream>
#include <vector>
using namespace std;
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

void show_Vector(vector<int>& nums){
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main(){
    //vector<int> nums1 = {1,2}, nums2 = {3,4};
    //vector<int> nums1 = {3}, nums2 = {-2,-1};
    //vector<int> nums1 = {1,3}, nums2 = {2,7};
    //vector<int> nums1 = {1,3}, nums2 = {2};
    //vector<int> nums1 = {0,0,0,0,0}, nums2 = {-1,0,0,0,1};
    vector<int> nums1 = {1,2,3,4,5}, nums2 = {-1,2,5,8,9};
    show_Vector(nums1);
    show_Vector(nums2);

    double Ret = findMedianSortedArrays(nums1,nums2);
    cout << Ret << endl;
    return 0;
}