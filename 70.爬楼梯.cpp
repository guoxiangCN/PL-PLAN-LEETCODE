/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <map>
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        std::map<int, int> cache;
        return climbStairs0(n - 1, cache) + climbStairs0(n - 2, cache);
    }

    int climbStairs0(int n, std::map<int, int> &map)
    {
        if (map.find(n) != map.end())
        {
            return map[n];
        }

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int ret = climbStairs0(n - 1, map) + climbStairs0(n - 2, map);
        map[n] = ret;
        return ret;
    }
};
// @lc code=end
