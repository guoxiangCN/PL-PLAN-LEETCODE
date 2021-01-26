/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
#if 0
#define nullptr 0
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = new ListNode(0);
        ListNode *tmp = ret;

        int jin = 0;
        while (l1 || l2 || jin != 0)
        {
            int l1Nbr = l1 ? l1->val : 0;
            int l2Nbr = l2 ? l2->val : 0;

            int sum = l1Nbr + l2Nbr + jin;
            if (sum >= 10)
            {
                jin = 1;
                sum %= 10;
            }
            else
            {
                jin = 0;
            }

            tmp->next = new ListNode(sum);
            tmp = tmp->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return ret->next;
    }
};
// @lc code=end
