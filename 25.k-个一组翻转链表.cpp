/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define _LOCAL_DEBUG_

#ifdef _LOCAL_DEBUG_
#ifdef __cplusplus
#define nullptr 0 // fuck vscode
#else
#define NULL ((void *)0)
#define nullptr NULL // fuck vscode
#endif
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

#define SWAP_CUR_NEXT(prev, cur, next)                                         \
  do {                                                                         \
    ListNode *nn = next.next;                                                  \
    prev->next = next;                                                         \
    next->next = cur;                                                          \
    cur->next = nn;                                                            \
  } while (0)

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) { //
    ListNode *gfirst = head, *glast = head, *gstub = head;
    int tk = k;
    int kCount = 0;
    while (gfirst->next) {
      while (tk > 0) {
        if (glast->next) {
          gstub = glast;
          glast = glast->next;
          tk--;
        }
        break;
      }
      if (tk == 0) {
        reverseRange(gfirst, glast, &head, &gstub);
      } else {
        reverseRange(gfirst, glast, nullptr, &gstub);
      }
      kCount++;
      tk = k;
    }
    return head;
  }

  void reverseRange(ListNode *pFirst, ListNode *pLast, ListNode **ppRangeHead,
                    ListNode **ppRangeTail) {

    if (ppRangeHead) {
      *ppRangeHead = pLast;
    }

    if (ppRangeTail) {
      *ppRangeTail = pFirst;
    }

    // p c n
    // A B C D
    // c p   c
    // B A C D
    ListNode *pPrev = pFirst;
    ListNode *pCur = pFirst->next;
    ListNode *pNext = nullptr;
    while (/* pCur != nullptr && */ pCur != pLast) {
      // save next
      pNext = pCur->next;
      // swap prev and cur
      pCur->next = pPrev;  // B.next = A
      pPrev->next = pNext; // A.next = C
      // prepare for next
      pPrev = pCur;
      pCur = pNext;
    }
    pCur->next = pPrev;
  }
};
// @lc code=end
