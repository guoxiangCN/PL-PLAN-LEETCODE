/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 * 2
 * 4
 * 8
 * 16
 */

#include <cstddef>

// @lc code=start
class Solution {
public:
  bool isPowerOfTwo(int n) {
    int x = 0;
    for (size_t i = 0; i < sizeof(int) * 8; i++) {
      if (n >> i & 0x0001) {
        x++;
      }
    }
    return n > 0 && x == 1;
  }
};
// @lc code=end
