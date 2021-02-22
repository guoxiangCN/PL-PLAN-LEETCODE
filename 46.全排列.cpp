/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列

 *
 */
#include <vector>
#include <map>

using std::vector;

// @lc code=start
class Solution {
public:
    // 这个解法效率太低 TODO TODO TODO
    vector<vector<int> > permute(vector<int>& nums) {
        if(!nums.size())  return res_   ;
        std::vector<int> tmp_res;   
        std::map<int,bool> used;
        back_trace(nums, tmp_res, used);
        return res_;
    }
   private:
     vector<vector<int> > res_;

     void back_trace(std::vector<int> &nums, 
                std::vector<int> &tmp_res, std::map<int,bool> used) {

        if(tmp_res.size() == nums.size()) {
            res_.push_back(tmp_res);
            return;
        }

        for(auto &n : nums) {
            if(!used[n]) {
                used[n] = true;
                tmp_res.push_back(n);
                back_trace(nums, tmp_res, used);

                tmp_res.pop_back();
                used[n]=false;
            }
        }


     } 
};
// @lc code=end

