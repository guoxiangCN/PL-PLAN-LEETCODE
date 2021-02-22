/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
using std::string;

// @lc code=start

class Solution {
public:
    int myAtoi(string s) {
        int res = 0, sign = 1, pos = 0;
        while(s[pos] == ' ') pos++;
        if(s[pos] == '-') {
            sign = -1;
            pos++;
        }
        for(int i = pos; i < s.length(); i++) {
            res = res * 10 + static_cast<int>(s[i]-'0');
        }
        return res * sign;
    }
};
// @lc code=end

