#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string num2str(long long num){
        if(num==0)return "0";
        if(num>0){
            string str;
            while(num){
                str.push_back(num%10+'0');
                num/=10;
            }
            for(int i=0;i<str.size()/2;++i)
            swap(str[i],str[str.size()-1-i]);
            return str;
        }
        else{
            num = -num;
            string str;
            while(num){
                str.push_back(num%10+'0');
                num/=10;
            }str.push_back('-');
            for(int i=0;i<str.size()/2;++i)
            swap(str[i],str[str.size()-1-i]);
            return str;
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> Ret;
        if(nums.size()==0)return Ret;
        int N=nums.size();
        nums.push_back(nums.back()-1);

        for(int i=0;i<N;++i){
            if(nums[i]==nums[i+1]-1){
                Ret.push_back(num2str(nums[i])+"->");
                do{++i;}
                while(nums[i]==nums[i+1]-1);
                Ret.back() += num2str(nums[i]);
            }else Ret.push_back(num2str(nums[i]));
        }
        return Ret;
    }
};

int main(){
    
    vector<int> nums = {0,2,3,4,6,8,9,111};
    
    Solution T;
    vector<string> ans = T.summaryRanges(nums);
    for(int i=0;i<ans.size();++i)
    cout<<ans[i]<<" ";
    cout<<endl;
    getchar();
    return 0;
}