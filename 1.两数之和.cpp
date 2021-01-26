/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
using std::vector;
// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::vector<int> ret;
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < nums.size(); j++) {
        if (i == j) {
          continue;
        }
        if (nums[i] + nums[j] == target) {
          ret.assign({static_cast<int>(i), static_cast<int>(j)});
        }
      }
    }
    return ret;
  }
};
// @lc code=end
