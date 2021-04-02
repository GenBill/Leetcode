#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    /*
    vector<int> countList(int numRows, int i){
        int jump = (numRows-1)*2;
        if(i==0||i==numRows-1)return {jump, jump};
        return {jump-2*i, 2*i};
    }
    */
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
        string Ret;
        Ret.reserve(numRows);
        //int jump = (numRows-1)*2;
        for(int i=0; i<numRows; i++){
            int a, b;
            if(i==0||i==numRows-1){
                a = numRows+numRows-2;
                b = numRows+numRows-2;
            }else{
                a = numRows+numRows-i-i-2;
                b = i+i;
            }

            //vector<int> jumpList = countList(numRows, i);
            int j = i;
            bool k = 0;
            while(j<s.length()){
                Ret += s[j];
                j += k ? b:a;
                k = k ? 0:1;
            }
        }
        return Ret;
    }
};
// @lc code=end

