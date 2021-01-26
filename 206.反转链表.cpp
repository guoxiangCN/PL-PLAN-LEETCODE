/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define __LOCAL_DEBUG__ 1

#if defined(__LOCAL_DEBUG__) && __LOCAL_DEBUG__
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
  /**
   * 原地反转,最多使用几个指针
   */
  ListNode *reverseList(ListNode *head) {
    // FIXME
    return NULL;
  }

  /**
   * 本方法需要额外占用一个辅助接点的空间
   */
  ListNode *reverseList_method1(ListNode *head) {
    ListNode *pCur = head;
    ListNode *pNext = NULL;

    ListNode *tmp = head;
    ListNode marry(-1);

    while (pCur) {
      pNext = pCur->next;
      tmp = marry.next;
      pCur->next = tmp;
      // fix position
      marry.next = pCur;
      pCur = pNext;
    }
    return marry.next;
  }
};
// @lc code=end
