/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>
#include <algorithm>

// TODO:RE

using std::vector;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size() - 1 - i; j++)
            {
                if (nums[j] == 0)
                {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};
// @lc code=end
