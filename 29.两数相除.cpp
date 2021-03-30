/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    long long cheng(long long a,long long b){
        if(b<a)swap(a,b);
        long long Ret=0;
        while(a){
            if(a&1)Ret+=b;
            a>>=1;
            b+=b;
        }
        return Ret;
    }
    int divide(int x, int y){
        long long a=x,b=y;
        if(a==-2147483648&&b==-1)return 2147483647;
        if((a>0&&b>0)||(a<0&&b<0)){
            a=abs(a);
            b=abs(b);
            if(b>a)return 0;

            long long i=2,chen=b;chen+=b;
            while(chen<a){
                i+=i;
                chen+=chen;
            }
            long long left=i>>1,right=i;
            while(left<=right){
                i = (left+right)>>1;
                chen = cheng(i,b);
                if(chen<=a&&chen+b>a)return i;
                if(chen<a)left=i+1;
                else right=i-1;
            }
            return right;
        }
        else{
            a=abs(a);
            b=abs(b);
            if(b>a)return 0;
            long long i=2,chen=b;chen+=b;
            while(chen<a){
                i+=i;
                chen+=chen;
            }
            long long left=i>>1,right=i;
            while(left<=right){
                i = (left+right)>>1;
                chen = cheng(i,b);
                if(chen<=a&&chen+b>a)return -i;
                if(chen<a)left=i+1;
                else right=i-1;
            }
            return -right;
        }
    }
};
// @lc code=end

