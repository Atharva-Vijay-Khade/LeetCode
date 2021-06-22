

// swap nodes in pair 

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
    
    ListNode* swapPairs(ListNode* head) {
        
        // We can solve this using iterative method -> theta(N)
        // We can solve this using recursion as well -> theta(N) + theta(N)
        
        // changing links will be better than swapping !
        
        // 1] Assuming a hypothesis that swapPairs(ListNode*) will return me the head pointer pointing to n-2 nodes list
        // 2] In the inductio step, we can change the links of the current two nodes and return the head
        // 3] Base case will, if we have head as NULL [size if even] we returning NULL if head not NULL [size is odd] return head
        
        // try out a tail recursive solution 
        
        // Base Case 
        if(head == NULL)     // when size is even
            return NULL;
        
        if(head->next==NULL) // when size is odd
            return head;
        
        // hypothesis
        ListNode *nextHead = swapPairs(head->next->next);
        ListNode *newHead = head->next;
        
        head->next->next = head;
        head->next = nextHead;
        
        return newHead;
        
    }
    
};