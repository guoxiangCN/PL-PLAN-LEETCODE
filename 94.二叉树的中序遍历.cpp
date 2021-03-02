/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <vector>
using std::vector;

#if 0
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
#endif
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        helperfunc(root, res);
        return res;
    }

    void helperfunc(TreeNode *root, std::vector<int> &res)
    {
        if(!root) return;

        if(root->left) {
            helperfunc(root->left, res);
        }

        res.push_back(root->val);
        
        if(root->right) {
            helperfunc(root->right, res);
        }
    }

};
// @lc code=end

