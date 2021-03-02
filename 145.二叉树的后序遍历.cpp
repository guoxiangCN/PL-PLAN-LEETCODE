/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        helperfunc(root, res);
        return res;
    }

    void helperfunc(TreeNode *root, std::vector<int> &res)
    {
        if(!root) return;

        if(root->left) {
            helperfunc(root->left, res);
        }

        
        if(root->right) {
            helperfunc(root->right, res);
        }


        res.push_back(root->val);
    }
};
// @lc code=end

