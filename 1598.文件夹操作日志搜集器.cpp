/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
  int minOperations(vector<string> &logs) {
    std::stack<int> s;
    for (auto &log : logs) {
      if (log == "../") {
        if (!s.empty()) {
          s.pop();
        }
      } else if (log == "./") {
        // NOP
      } else {
        s.push(0);
      }
    }
    return s.size();
  }
};
// @lc code=end
