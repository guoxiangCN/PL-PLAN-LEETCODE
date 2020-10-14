/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start

#include <vector>
#include <cassert>

using std::vector;

// #define _DEBUG_



#ifdef _DEBUG_
#include <iostream>
using namespace std;
#endif


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        signed int i = digits.size() - 1;
        for (; i >= 0; i--)
        {
            int cur = digits[i];
            if(cur + 1 < 10) {
                digits[i] = cur + 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }

        // overflow.
        if (i < 0) {
            digits.insert(digits.cbegin(), {1});
        }
            
        return digits;
    }
};

#ifdef _DEBUG_
void printX (int i) {  // function:
  cout << i << ", ";
}

int main(int argc, const char *argv[])
{
    Solution sol;
    std::vector<int> src = {9};
    auto ret = sol.plusOne(src);
    std::cout << "ret size ->" << ret.size() << std::endl;
    // std::for_each(ret.begin(), ret.end(), printX);
    return 0;
}

#endif
// @lc code=end

