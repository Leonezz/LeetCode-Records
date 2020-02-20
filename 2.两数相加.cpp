/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * Author:zhuwenq
 * Date:2 20 2020
 * 按位相加，过十进位
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        int carry = 0;
        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            res->val = sum % 10;
            carry = sum / 10;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            if (l1 || l2)
            {
                res->next = new ListNode(0);
                res = res->next;
            }
            else if (carry > 0)
            {
                res->next = new ListNode(carry);
            }
        }

        return head;
    }
};
// @lc code=end
