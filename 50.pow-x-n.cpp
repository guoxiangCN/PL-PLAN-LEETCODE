/*
 * @lc app=leetcode.cn id=50 lang=cpp

 * [50] Pow(x, n)
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 *
 *
 * 3^19 = 3 ^ 16 * 3^2 * 3^1
 * 10011
 */

// @lc code=start
#include <stdint.h>

class Solution {
public:
  double myPow(double x, int n) {
    if (x == 0)
      return 1;

    double ret = 1;
    int64_t nn = n < 0 ? (-1 * n) : n;

    while (nn) {
      if (nn & 0x1) {
        ret *= x;
      }
      nn >>= 1;
      x *= x;
    }
    return n < 0 ? (1 / ret) : ret;
  }
};
// @lc code=end
