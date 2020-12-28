/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <set>
#include <vector>

using std::vector;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    std::set<int> s(nums.cbegin(), nums.cend());
    return s.size() != nums.size();
  }
};
// @lc code=end
