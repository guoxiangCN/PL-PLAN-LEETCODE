/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <vector>
#include <string>
#include <cassert>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        assert(n > 0);
        std::vector<std::string> v;
        std::string tmp = "";
        for (size_t i = 1; i <= n; i++)
        {
            tmp = std::to_string(i);
            if(i % 3 == 0) {
                tmp = "Fizz";
            }
            if(i % 5 == 0) {
                tmp = "Buzz";
            }
            if (i % 15 == 0)
            {
                tmp = "FizzBuzz";
            }
            v.push_back(tmp);
        }
        return v;
    }
};
// @lc code=end

