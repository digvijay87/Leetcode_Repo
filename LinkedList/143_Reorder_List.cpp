/*

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
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

//10 20 30 40 50

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) 
            return;
        
        ListNode* cur = head;
        vector<ListNode*> vec;
        int len = 0;
        
        while(cur)
        {
            vec.push_back(cur);
            cur = cur->next;
            len++;
        }
        
        int l = vec.size() - 1;
        
        cur = head;
        for(int i = 0; i < len/2 ; i++)
        {
            if( i == len/2-1 && len % 2 == 0 )
            {
                cur = cur->next;
                break;
            }
            ListNode* node = vec[l];
            ListNode* temp = new ListNode(node->val);
            
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
            l--;
        }
          //  printf("i = %d\n",i);
         
        cur->next = NULL;
        
    }
};
