/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

#include <queue>
#include <vector>

using std::vector;

// 方法一:最小堆
// Accepted
// 32/32 cases passed (20 ms)
// Your runtime beats 73.98 % of cpp submissions
// Your memory usage beats 15.25 % of cpp submissions (10 MB)

// 方法二:快排指针 FIXME
// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    // 最小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int i = 0;
    for (; i < k; ++i) {
      minHeap.push(nums[i]);
    }
    for (; i < nums.size(); ++i) {
      if (nums[i] > minHeap.top()) {
        minHeap.pop();
        minHeap.push(nums[i]);
      }
    }
    return minHeap.top();
  }
};
// @lc code=end
