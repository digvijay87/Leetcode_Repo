/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        int len = 0;
        ListNode*temp = head;
        
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        
        //Find the actual moves for example if size of list is 5 and k is 33 so l will become 33%5 = 3
        k = k % len;
      
        //Move the fats kth time ahead have a difference between slow and fast
        while(k--)
        {
            fast = fast->next;
            
        }
        
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
      
        if(slow->next){
            ListNode* cur = slow->next;
            fast->next = head;
            slow->next = NULL;
            head = cur;
            //return head;
        }
        return head;
    }
};

