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
/* Brute force ***
[1,2,3,4,5] k = 2
move the cursor k time untill you find NULL
1 2 | 3 4
keep the first node's refrence;
1 | 3

for the fisr time keep the prevs head as NULL.
previous head = NULL | prevhead = 2
once you reached kth node reverse the node. and mark tail as head and prevs head
NULL<-1<-2 (2 is head) 1 pointing to prevhead i.e. NULL (prevhead = 2) (head = 2)
NULL<-1<-2 <-4 <-3  3 is pointing to 2 (prevhead = 4 (head = 4))
refere the new tail's next is previous head.
if the you reach NULL before k traversal point new head to first refrence

Input: head = [1,2,3,4,5], k = 2
NULL <- 2 <-1 <-
1<-3<-4 
Output: [2,1,4,3,5]
*/
// NULL <- 1 <- 2 <- 3 <- 4 
/*
class Solution {
private : 
    ListNode* phead = NULL;
    
public:
    ListNode* reverse(ListNode *head, Listnode *tail){
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = head;
        
        while(cur != tail)
        {
            //ListNode* temp = cur;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        //phead = prev;
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pHead = NULL;
        ListNode *tail = NULL;
        ListNode *nHead = head;
        ListNode *cur = head;
        ListNode *ntail;
    
        int i = 1;
        while(cur)
        {
            if(i == k)
            {
                ntail = cur->next;
                
                //ntail->next = NULL;
                pHead = reverse(nHead,ntail);
                i = 1;
                cur = ntail;
                
            }else{
                cur = cur->next;
                i++;
            }
        }
    }
};
*/

// recursive solution

class Solution {
    public:
    ListNode* reverse(ListNode *head, ListNode *tail){
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = head;
        
        while(cur != tail)
        {
            //ListNode* temp = cur;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        //phead = prev;
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        
        for(int i = 0; i < k; i++)
        {
            if(node == NULL)
                return head;
            node = node->next;
        }
        
        ListNode* newNode = reverse(head, node);
        
        head->next = reverseKGroup(node, k); // This is the beauty of recusrion 
        
        return newNode;
    }
};
