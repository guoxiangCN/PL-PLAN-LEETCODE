/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using std::vector;

#if 0
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#endif

class Solution {
public:

    using res_t = std::vector<std::vector<int> >;

    vector<vector<int>> levelOrder(TreeNode* root) {
        res_t res;
        if(!root) return res;

        std::queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int curLevelNbr = Q.size();
            std::vector<int> curLevelVals;
            for(int i = 0; i< curLevelNbr; i++) {
                TreeNode *tmp = Q.front();
                curLevelVals.push_back(tmp->val);
                if(tmp->left) Q.push(tmp->left);
                if(tmp->right) Q.push(tmp->right);
                Q.pop();
            }
            res.push_back(curLevelVals);
        }
        return res;
    }
};
// @lc code=end

