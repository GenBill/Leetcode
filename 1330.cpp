#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;
        int gain = 0;        
        int hi = INT_MIN;
        int lo = INT_MAX;
        for (int i = 0; i<n-1; ++i) {
            int n1 = nums[i];
            int n2 = nums[i + 1];
            sum += abs(n1-n2);
            gain = max(gain, abs(nums[0]-n2)-abs(n1-n2));
            gain = max(gain, abs(nums[n-1]-n1)-abs(n1-n2));
            hi = max(hi, min(n1, n2));
            lo = min(lo, max(n1, n2));
        }
        return sum + max(gain, (hi-lo) * 2);
    }
};

int main(){
    
    vector<int> nums = {1,2,5,7,4};
    
    Solution T;
    int ans = T.maxValueAfterReverse(nums);
    printf("%d\n",ans);
    return 0;
}