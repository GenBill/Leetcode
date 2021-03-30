#include <iostream>
#include <vector>
using namespace std;

struct Onga{
    int length;
    int times;
    Onga(int l,int t):length(l),times(t){}
};

Onga CountOnga(vector<int>& nums,int index,int minH,int times) {
    if(index>=nums.size())return Onga(0,1);
    if(nums[index]<=minH)return CountOnga(nums,index+1,minH,times);
    //else return max();
    Onga a = CountOnga(nums,index+1,nums[index],times);
        a.length++;
    Onga b = CountOnga(nums,index+1,minH,times);
    if(a.length==b.length){
        a.times+=b.times;
        return a;
    }
    else if(a.length>b.length)return a;
    else return b;
}


int main(){
    vector<int> nums;
    //nums = {1,3,5,4,7};
    nums = {1,1,1,1,1};
    //nums = {7,6,5,4,3,2};
    Onga ans = CountOnga(nums,0,-(0x7fffffff),0);
    printf("%d\n",ans.times);
    getchar();
    return 0;
}