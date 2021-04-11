#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1), idx(3, 0);
        for (int i = 1; i < n; ++i){
            int a = ugly[idx[0]]*2, b = ugly[idx[1]]*3, c = ugly[idx[2]]*5;
            int next = std::min(a, std::min(b, c));
            if (next == a){
                ++idx[0];
            } 
            if (next == b){
                ++idx[1];
            } 
            if (next == c){
                ++idx[2];
            }
            ugly[i] = next;
        }
        return ugly.back();
    }
};
// @lc code=end

