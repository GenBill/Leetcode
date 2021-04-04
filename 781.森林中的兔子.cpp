#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int Ans[1000] = {0};
        for(int i=0; i<answers.size(); i++){
            Ans[answers[i]]++;
        }
        int sum = 0;
        for(int i=0; i<1000; i++){
            if(Ans[i]){
                if(Ans[i]%(i+1)==0){
                    sum += Ans[i];
                }else{
                    sum += (1+Ans[i]/(i+1))*(i+1);
                }
            }
        }
        return sum;
    }
};
// @lc code=end

