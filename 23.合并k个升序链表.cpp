/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
 #include <vector>
 #include <queue>
 using std::vector;

//  struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

  struct ListNodePtrCompare  {
      bool operator()(ListNode* ptrA, ListNode * ptrB) const {
          return ptrA->val > ptrB->val;
      }
  };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodePtrCompare > min_heap;
        for(int i = 0; i<lists.size(); i++) {
            if(lists[i]) {
                min_heap.push(lists[i]);
            }
        }

        if(min_heap.empty()) return nullptr;

        ListNode dummy, *pCurrent = nullptr, *pMin = nullptr;
        dummy.next = min_heap.top(); min_heap.pop();
        
        pMin = dummy.next;
        pCurrent = dummy.next;

        // for_each
        for(; !min_heap.empty() ;) {
            if(pMin->next) {
                min_heap.push(pMin->next);
                pMin = min_heap.top();
                min_heap.pop();


            } else {
                pMin = min_heap.top();
                min_heap.pop();
            } 
             pCurrent->next = pMin;
             pCurrent = pCurrent->next;
        }


        return dummy.next;
    }
};
// @lc code=end

