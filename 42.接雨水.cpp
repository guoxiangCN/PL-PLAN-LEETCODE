/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

 #include <vector>
 #include <iostream>
 #include <algorithm>
 using std::vector;

// @lc code=start
class Solution {
public:
    int trap1(vector<int>& height) {
        // 非dp解法:
        if(height.size() == 0) return 0;
        int sum = 0;
        for(int i = 1 ; i < height.size() - 1; i++) {
            int lMax = 0, rMax = 0;
            // find lMax 
            for(int j = i-1; j >= 0; j--) {
                lMax = std::max(lMax, height[j]);
            }
            // find rMax
            for(int j = i+1; j < height.size(); j++) {
                rMax = std::max(rMax, height[j]);
            }
            // cmp
            int min = std::min(lMax, rMax);
            if(min > height[i]) {
                sum += (min-height[i]);
            }
        }
        return sum;
    }

    // save answer of sub-question
    int trap(vector<int> & height) {
        if(height.size() == 0) return 0;

        std::vector<int> lMaxStore(height.size(), 0);
        std::vector<int> rMaxStore(height.size(), 0);

        for(int i = 1; i < height.size() - 1; i++) {
            lMaxStore[i] = std::max(height[i-1], lMaxStore[i-1]);
        }
        for(int i = height.size()-2; i>=0; i--) {
            rMaxStore[i] = std::max(height[i+1], rMaxStore[i+1]);
        }

        int sum = 0;
        for(int i = 1; i < height.size() - 1; i++) {
            int min = std::min(lMaxStore[i], rMaxStore[i]);
            if(height[i] < min) {
                sum += (min - height[i]);
            }
        }

        return sum;

    }
};

// int main(int argc, char** argv) {
//     std::vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
//     Solution sol;
//     int val = sol.trap(vec);
//     std::cout << "val" << val << std::endl;
//     return 0;
// }
// @lc code=end

