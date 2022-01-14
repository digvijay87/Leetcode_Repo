/*
##Easy

Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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

// 1st Approach is using a vector this is easy to implement but expensive because we any way have travesre 2 times so its O(N) also extra vector is being used so 
// Space complexity is O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL)
            true;
        ListNode* cur = head;
        vector<int> vec;
        while(cur)
        {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        
        int l = 0;
        int r = vec.size() - 1;
        
        while(r>l)
        {
            if(vec[r] != vec[l])
                return false;
            
            r--;
            l++;
        }
        return true;
    }
};
*/

//2nd Approach in this apprach we do use any extra space so space complexity is O(1) and its linear travesal so time complexity is O(1)

class Solution {
public:    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast)
            slow = slow->next;
        
        ListNode* firstHalf = head;
        ListNode* secondHalf = reverse(slow);
        
        while(secondHalf)
        {
            if(firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;  
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        
        while(curr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        head = prev;
        return head;
    }
};
