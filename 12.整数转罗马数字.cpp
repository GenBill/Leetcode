#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        short numList[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romaList = "M CMD CDC XCL XLX IXV IVI";
        //vector<string> romaList = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string Ret;
        int i = 0;
        while(num){
            if(num >= numList[i]){
                num -= numList[i];
                if(i%2){
                    Ret += romaList[i+i];
                    Ret += romaList[i+i+1];
                }else{
                    Ret += romaList[i+i];
                }
            }else{
                i++;
            }
        }
        return Ret;
    }
};
// @lc code=end

