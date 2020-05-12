/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;
        int last = 0;
        ListNode *t = head;
        while (t->next != NULL)
        {
            last = t->val;
            if (t->next->val == last)
            {
                ListNode *temp = t->next;
                t->next = temp->next;
                delete temp;
                if (t->next == NULL)
                    break;
                continue;
            }
            t = t->next;
        }
        return head;
    }
};
// @lc code=end
