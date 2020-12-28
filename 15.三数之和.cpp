/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * Time Limit Exceeded......... 315/318 cases passed (N/A)
 */
#include <iostream>
#include <set>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
  vector<vector<int> /**/> threeSum(vector<int> &nums) {
    std::stable_sort(nums.begin(), nums.end());
    std::set<std::vector<int> /**/> set;
    size_t size = nums.size();

    for (size_t cursor = 0; cursor < size; cursor++) {
      // size_t left = 0, right = size - 1;
      for (int left = 0; left < cursor; left++) {
        for (int right = size - 1; right > cursor; right--) {
          if (nums[left] + nums[cursor] + nums[right] == 0) {
            std::vector<int> tmp({nums[left], nums[cursor], nums[right]});
            std::sort(tmp.begin(), tmp.end());
            set.insert(std::move(tmp));
          }
        }
      }
    }
    return vector<vector<int> /**/>(set.begin(), set.end());
  }
};

// int main(int argc, char **argv) {
//   Solution sol;
//   std::vector<int> input = {-1, 0, 1, 2, -1, -4};
//   auto ret = sol.threeSum(input);
//   return 0;
// }
// @lc code=end
