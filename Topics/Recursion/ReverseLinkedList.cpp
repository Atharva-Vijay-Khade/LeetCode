
// Reverse a linked List 

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
    ListNode* reverseWrapper(ListNode *head,ListNode *&HEAD) {
        
        // Naive : copy list in another array
        //       : and change original list traversing reverse in array
        //       : time : theta(N) + space : theta(N)
        
        // Optimal : IBH method  
        //         : Hypothesis => reverseList(head) will return me the last pointer 
        //           of the reversed list and has head already set up
        //         : induction => connect current node wiht this last node and make last as current
        //         : base case => when we reach the last node or the nodes is empty 
        
        // Iterative Optimal : Take first on node 1 
        //                   : Take second on node 2
        //                   : preserve the next of node 2
        //                   : reverse the link between node 1 and node 2
        //                   : go on preserve and repeat the same process 
        //                   : at the end we return the head 
        
        // Base Case 
//         if(head == NULL||head->next==NULL) {
//             HEAD = head;
//             return head;
//         }
        
//         // Hypothesis
//         ListNode *last = reverseWrapper(head->next,HEAD);
        
//         // Induction
//         last->next = head;
//         head->next = NULL;
//         last=head;
        
//         return head;
        
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode *HEAD;
        // reverseWrapper(head,HEAD);
        // return HEAD;
        
        
        // Better Recursive Solution taken from most votes
        
//         if(head==NULL||head->next==NULL)
//             return head;
        
//         ListNode *node = reverseList(head->next);
//         head->next->next=head;
//         head->next=NULL;
//         return node;
        
        //Iterative Solution { most optimal solution }
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *prev = NULL;
        ListNode *curr = NULL;
        ListNode *Next = head;
        
        while(Next!=NULL) {
            
            curr=Next;
            Next=Next->next;
            curr->next=prev;
            prev=curr;
        
        }
        
        return curr;
        
    }
};