/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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

/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/
/*
class Solution {
private:
    ListNode *ntail = NULL;
public:
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* prev = NULL;
        ListNode* next = head;
        ListNode* cur = head;
        //nhead = head;
        while(cur != tail)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        printf("ntail %d\n",ntail->val);
        printf("head %d",head->val);
        head->next = ntail;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 0;
        ListNode *cur = head;
        ListNode *prev;
        //ListNode *ntail;
        
        for(i = 0; i < left-1; i++)
        {
            if(cur == NULL)
                return head;
            if(i < left-1){
                prev = cur;
            }
            cur = cur->next;
        }
        //printf("%d %d\n",left,right);
        ListNode *tail = cur;
        for(; i < right; i++)
        {
            if(tail == NULL)
                return head;
            
            tail = tail->next;
            ntail = tail;
        }
        printf("tail %d",tail->val);
        printf("cur %d\n",cur->val);
        //printf("ntail %d\n",ntail->val);
        prev->next = reverse(cur,tail);
        
        ntail->next = NULL;
        return head;
        
    }
};
*/


class Solution {
public:
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
       dummy -> next = head;
       for (int i = 0; i < m - 1; i++) {
           pre = pre -> next;
       }
       cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* temp = pre -> next;
           pre -> next = cur -> next;
           cur -> next = cur -> next -> next;
           pre -> next -> next = temp;
       }
       return dummy -> next;
   }
};
