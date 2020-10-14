/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if ((n >> i) & 0x00000001 == 1)
                weight++;
        }
        return weight;
    }
};
// @lc code=end

