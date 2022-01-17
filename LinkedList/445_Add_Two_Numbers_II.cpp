/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0;
        int n2 = 0;
        ListNode* cur1 = l1;
        ListNode *cur2 = l2;
        
        while(cur1)
        {
            cur1 = cur1->next;
            n1++;
        }
        
        while(cur2)
        {
            cur2 = cur2->next;
            n2++;
        }
        
        
        ListNode *head = NULL;
        cur1 = l1;
        cur2 = l2;
        
        while(n1 > 0 && n2 > 0)
        {
            int val = 0;
            if(n1 >= n2){
                val += cur1->val;
                cur1 = cur1->next;
                --n1;
            }
            if(n1 < n2)
            {
                val += cur2->val;
                cur2 = cur2->next;
                --n2;
            }
            
            ListNode* cur = new ListNode(val);
            cur->next = head;
            head = cur;
        }
        
        cur1 = head;
        int carry = 0 ;
        head = NULL;
        while(cur1 != NULL)
        {
            int val = (cur1->val + carry) % 10;
            carry = (cur1->val + carry) / 10;
            
            ListNode *cur = new ListNode(val);
            cur->next = head;
            head = cur;
            cur1 = cur1->next;
            
        }
        
        if(carry != 0)
        {
            ListNode *cur = new ListNode(carry);
            cur->next = head;
            head = cur;
        }
        return head;
    }
};
