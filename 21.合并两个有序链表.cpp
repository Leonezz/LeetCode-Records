/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *result = l1->val < l2->val ? l1 : l2;
        ListNode *toMerge = l2->val > l1->val ? l2 : l1;
        ListNode *temp = NULL;
        while (toMerge != NULL)
        {
            while (result != NULL && result->next != NULL &&
                   result->val < toMerge->val &&
                   toMerge->val > result->next->val)
            {
                result = result->next;
            }
            temp = toMerge->next;
            toMerge->next = result->next;
            result->next = toMerge;
            toMerge = temp;
        }
        return l1->val < l2->val ? l1 : l2;
    }
};
// @lc code=end
