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
        long long res = 0, sign = 1, pos = 0;
        while(s[pos] == ' ') pos++;

        if(!IsValidNumberChar(s[pos])) {
            if(s[pos] != '-' && s[pos] != '+') {
                return 0;
            }
        }

        if(s[pos] == '-') {
            sign = -1;
            pos++;
        } else if(s[pos] == '+') {
            pos++;
        }

        for(int i = pos; i < s.length(); i++) {
            if(IsValidNumberChar(s[i])==false) break;
            res = res * 10 + static_cast<long long>(s[i]-'0');
        }

        if(res < static_cast<long long>(0xffffffff80000000)) {
            return 0x80000000;
        }
        if(res > 0x7ffffffff) {
            return 0x7fffffff;
        }
        
        return res * sign;
    }

    private:
    bool IsValidNumberChar(char c) {
        return c >= '0' and c <= '9';
    }
};
// @lc code=end

