#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    void clean2(int &n){
        while(n%2==0)
            n/=2;
    }
    void clean3(int &n){
        while(n%3==0)
            n/=3;
    }
    void clean5(int &n){
        while(n%5==0)
            n/=5;
    }
    bool isUgly(int n){
        if(n==0)return 0;
        clean2(n);
        clean3(n);
        clean5(n);
        if(n==1)return 1;
        return 0;
    }
};
// @lc code=end

