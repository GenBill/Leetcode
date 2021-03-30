#include <iostream>
#include <vector>
using namespace std;

struct Onga{
    int length;
    int times;
    Onga():length(-1),times(-1){}
    Onga(int l,int t):length(l),times(t){}
};
vector<Onga> DP(2010,Onga(1,1));

Onga CountOnga(vector<int>& nums,int index,int minH) {
    if(index>=nums.size())return Onga(0,1);
    if(nums[index]<=minH)return CountOnga(nums,index+1,minH);
    //else return max();
    Onga a = CountOnga(nums,index+1,nums[index]);
        a.length++;
    Onga b = CountOnga(nums,index+1,minH);
    if(a.length==b.length){
        a.times+=b.times;
        return a;
    }
    else if(a.length>b.length)return a;
    else return b;
}
int maxT = 1;
void GetOnga(vector<int>& nums) {
    for(int j=1;j<nums.size();++j){
        for(int i=0;i<j;++i){
            if(nums[i]<nums[j]){
                if(DP[j].length==DP[i].length+1){
                    DP[j].times += DP[i].times;
                }
                else if(DP[j].length<DP[i].length+1){
                    DP[j] = DP[i];
                    ++DP[j].length;
                }
            }
        }
        maxT = maxT>DP[j].length ? maxT:DP[j].length;
    }
    return ;
}


int main(){
    vector<int> nums;
    //nums = {1,3,5,4,7};
    //nums = {1,1,1,1,1};
    nums = {7,6,5,4,3,2};
    Onga ans = CountOnga(nums,0,-(0x7fffffff));
    printf("%d\n",ans.times);

    GetOnga(nums);
    ans = DP[0];
    int ret=0;
    for(int i=0;i<nums.size();++i){
        if(maxT==DP[i].length){
            ret += DP[i].times;
        }
    }
    printf("%d\n",ret);

    getchar();
    return 0;
}