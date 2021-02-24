/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>

using std::vector;
// @lc code=start
class Solution {
public:
    // 解法1： 找到波谷和波峰
    int maxProfit__1(vector<int>& prices) {
       if(prices.size()==0) return 0;
       int maxProfit = 0, minPrice = 0x7fffffff;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i]-minPrice;
            }
        }
        return maxProfit;
    }

    // 解法2: 
    int maxProfit(vector<int>& prices) {
        int curMax= 0; int totalMax= 0;
        for(int i = 1; i< prices.size(); i++) {
            curMax = std::max(0, curMax += prices[i]-prices[i-1]);
            totalMax = std::max(totalMax, curMax);
        }
       return totalMax;
    }
};
// @lc code=end

