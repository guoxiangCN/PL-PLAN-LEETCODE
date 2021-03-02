/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start

// Definition for a Node.
#include <queue>
#include <vector>
using std::vector;

#if 0
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> res;
        if(!root) return res;

        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int levelsize = q.size();
            std::vector<int> levelVals;
            for(int i = 0; i < levelsize; i++) {
                Node* tmp = q.front();
                levelVals.push_back(tmp->val);
                if(!tmp->children.empty()) {
                    for(auto it = tmp->children.begin(); it != tmp->children.end(); it++)
                    {
                        if(*it) {
                            q.push(*it);
                        }
                    }
                }
                q.pop();
            }
            res.push_back(levelVals);
        }
        return res;
    }
};
// @lc code=end

