
//Merge Two Sorted Lists

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
    
    ListNode* MergeHelper(ListNode *l1,ListNode *l2,ListNode *Head,ListNode *prev = NULL) {
        
        // Tail Recursive Solution
        
        //base case 
        
        if(l1==NULL) {
            prev->next = l2;
            return Head;
        }
        else if(l2==NULL) {
            prev->next = l1;
            return Head;
        }
        
        //Dealing intermediate decision state
        
        if(l1->val <= l2->val) {
            
            if(prev==NULL) {
                Head = l1;
                prev = Head;
            }
            else {
                prev->next = l1;
                prev = prev->next;
            }
            
            return MergeHelper(l1->next,l2,Head,prev);
            
        }
        else {
            
            if(prev==NULL) {
                Head = l2;
                prev = Head;
            }
            else {
                prev->next = l2;
                prev = prev->next;
            }
            
            return MergeHelper(l1,l2->next,Head,prev);
            
        }
        
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // Non Tail Recursive Solution
        
        //Base Case
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        
        // Intermediate decision state
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
        
    }
};