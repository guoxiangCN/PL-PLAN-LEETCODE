/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 */
// #include <cassert>

#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif

#if 0
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
  void deleteNode(ListNode *node) {
    // assert(node && node->next);
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
// @lc code=end
