#include <iostream>
#include <vector>
using namespace std;
    double singleMedian(vector<int>& nums) {
        int L = nums.size();
        int tar = L/2;
        if(L%2)return nums[tar];
        else return (nums[tar]+nums[tar-1])/2.0;
    }
    int Partition(vector<int>& arr, int i, int j){
        //均摊坏情况
        if(i<j){ 
            int ramdom=i+rand()%(j-i);
            swap(arr[i],arr[ramdom]);
            while(i<j){
                while(i<j&&arr[i]<=arr[j])j--;
                if(i<j)swap(arr[i],arr[j]);
                
                while(i<j&&arr[i]<=arr[j])i++;
                if(i<j)swap(arr[i],arr[j]);
            }
        }
        return i;
    }

    double QuickMax(vector<int>& arr, int left, int right,int k){
        int position = Partition(arr,left,right);
        if(position==k)return arr[position];
        else{
            if(position<k)return QuickMax(arr,position+1,right,k);
            else return QuickMax(arr,left,position-1,k);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0){
            if(nums1.size())return singleMedian(nums1);
            else return singleMedian(nums2);
        }
        vector<int> nums3;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        int L3 = nums3.size(), tar = L3/2;
        if(L3%2)return QuickMax(nums3,0,L3-1,tar);
        else return (QuickMax(nums3,0,L3-1,tar)+QuickMax(nums3,0,L3-1,tar-1))/2;
    }

void show_Vector(vector<int>& nums){
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main(){
    //vector<int> nums1 = {1,2}, nums2 = {3,4};
    vector<int> nums1 = {3}, nums2 = {-2,-1};
    //vector<int> nums1 = {1,3}, nums2 = {2,7};
    //vector<int> nums1 = {1,3}, nums2 = {2};
    //vector<int> nums1 = {0,0,0,0,0}, nums2 = {-1,0,0,0,1};
    show_Vector(nums1);
    show_Vector(nums2);

    double Ret = findMedianSortedArrays(nums1,nums2);
    cout << Ret << endl;
    return 0;
}