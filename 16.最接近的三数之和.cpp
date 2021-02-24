/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <algorithm>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ret = nums[0]+nums[1]+nums[2];
    int sum=0;
    for(int i = 0; i <= nums.size(); i++) {
      int L = i+1;
      int R = nums.size()-1;
      while(L < R) {
        sum = nums[i] + nums[L] + nums[R];
        if(sum == target) {
          return sum;
        } else if(sum < target) {
          L++;
        } else {
          R--;
        }
        if(std::abs(sum - target) < std::abs(ret - target)) {
          ret = sum;
        }
      }
    }

    return ret;
  }
};
// @lc code=end
