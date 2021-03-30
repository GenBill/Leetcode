#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<pair<int,int>,pair<int,int>> Gmap;

pair<int,int> CountOnga(vector<int>& nums,int index,int minH,int times) {
    if(index>=nums.size())return pair(0,1);
    if(nums[index]<=minH){
        if(!Gmap.count(pair(index+1,minH)))
            Gmap[pair(index+1,minH)]=CountOnga(nums,index+1,minH,times);
        return Gmap[pair(index+1,minH)];
    }
    //else return max();
    if(!Gmap.count(pair(index+1,nums[index])))
        Gmap[pair(index+1,nums[index])]=CountOnga(nums,index+1,nums[index],times);
    pair<int,int> a = Gmap[pair(index+1,nums[index])];
        a.first++;
    
    if(!Gmap.count(pair(index+1,minH)))
        Gmap[pair(index+1,minH)]=CountOnga(nums,index+1,minH,times);
    pair<int,int> b = Gmap[pair(index+1,minH)];


    if(a.first==b.first){
        a.second+=b.second;
        Gmap[pair(index,minH)] = a;
        return a;
    }
    else if(a.first>b.first){
        Gmap[pair(index,minH)] = a;
        return a;
    }
    else {
        Gmap[pair(index,minH)] = b;
        return b;
    }
}


int main(){
    vector<int> nums;
    //nums = {1,3,5,4,7};
    nums = {1,1,1,1,1};
    //nums = {7,6,5,4,3,2};
    pair<int,int> ans = CountOnga(nums,0,-(0x7fffffff),0);
    printf("%d\n",ans.second);
    getchar();
    return 0;
}