#include <iostream>
#include <vector>

#include <typeinfo>

using namespace std;
    void Pointer_swap(int* p1,int* p2){
        //cout<<*p1<<*p2<<endl;
        int temp;
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        //cout<<*p1<<*p2<<endl;
    }
    double singleMedian(vector<int>& nums) {
        int L = nums.size();
        int tar = L/2;
        if(L%2)return nums[tar];
        else return (nums[tar]+nums[tar-1])/2.0;
    }
    int* arr(vector<int>& nums1, vector<int>& nums2, int i){
        if(i>=nums1.size())return &nums2[i-nums1.size()];
        else return &nums1[i];
    }
    int Partition(vector<int>& nums1, vector<int>& nums2, int i, int j){
        //均摊坏情况
        if(i<j){ 
            int ramdom=i+rand()%(j-i);
            Pointer_swap(arr(nums1,nums2,i),arr(nums1,nums2,ramdom));
            while(i<j){
                while(i<j&&*arr(nums1,nums2,i)<=*arr(nums1,nums2,j))j--;
                if(i<j)Pointer_swap(arr(nums1,nums2,i),arr(nums1,nums2,j));
                
                while(i<j&&*arr(nums1,nums2,i)<=*arr(nums1,nums2,j))i++;
                if(i<j)Pointer_swap(arr(nums1,nums2,i),arr(nums1,nums2,j));
            }
        }
        return i;
    }

    double QuickMax(vector<int>& nums1, vector<int>& nums2, int left, int right,int k){
        int position = Partition(nums1,nums2,left,right);
        if(position==k)return *arr(nums1,nums2,position);
        else{
            if(position<k)return QuickMax(nums1,nums2,position+1,right,k);
            else return QuickMax(nums1,nums2,left,position-1,k);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0){
            if(nums1.size())return singleMedian(nums1);
            else return singleMedian(nums2);
        }
        int L3 = nums1.size()+nums2.size(), tar = L3/2;
        if(L3%2)return QuickMax(nums1,nums2,0,L3-1,tar);
        else return (QuickMax(nums1,nums2,0,L3-1,tar)+QuickMax(nums1,nums2,0,L3-1,tar-1))/2;
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
    //vector<int> nums1 = {1,2,3,4,5}, nums2 = {-1,0,0,0,1};
    show_Vector(nums1);
    show_Vector(nums2);

    double Ret = findMedianSortedArrays(nums1,nums2);
    cout << Ret << endl;
    return 0;
}