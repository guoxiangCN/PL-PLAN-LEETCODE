/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <stack>
#include <map>
#include <string>

using std::string;

namespace
{
    using CT = std::string::value_type;
    std::map<CT, CT> kvs = {{'(',')'},{'{','}'},{'[',']'}};
} // namespace


class Solution {
public:
    bool isValid(string s) {
        std::stack<std::string::value_type> stk;
        for(auto x : s) {
            if(stk.empty()) {
                stk.push(x);
            }
            else {
                std::string::value_type &top = stk.top();
                auto target= kvs.end();
                if((target = kvs.find(top)) != kvs.end()) {
                   if(target->second == x) {
                       stk.pop();
                   } else {
                       stk.push(x);
                   }
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end

