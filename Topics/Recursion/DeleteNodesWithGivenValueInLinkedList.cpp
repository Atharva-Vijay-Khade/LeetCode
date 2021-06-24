

// Delete Nodes with a given value in linked list 

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
    ListNode* removeElements(ListNode* head, int val,ListNode *prev=NULL,ListNode *HEAD = NULL) {
        
        // Iterative : maintain a previous pointer and delete current and change links theta(N) + O(1)
        // Recursive : IBH method 
        
        // Base case 
        if(head==NULL)
            return HEAD;
        
        // Hypothesis 
        
//         ListNode *getHead = removeElements(head->next,val);
        
//         // Induction Step
        
//         if(head->val==val) {
//             head->next=NULL;
//             delete head;
//             head = getHead;
//         }
//         else
//             head->next = getHead;

_______________________________________________________________________________________


           Trying tail recursive method 
//         ListNode *nextNode=head->next;
            
//         if(head->val == val){
            
//             if(prev==NULL)
//             {
                
//                 nextNode = head->next;
//                 HEAD = nextNode;
//                 delete head;
                
//             }
//             else {
                
//                 prev->next=head->next;
//                 head->next=NULL;
//                 delete head;
//                 nextNode = prev->next;
                
//             }
            
//         }
//         else {
//             if(prev==NULL)
//                 HEAD = head;
//             prev=head;
//         }
        
//         return removeElements(nextNode,val,prev,HEAD);
    
    }
    
};