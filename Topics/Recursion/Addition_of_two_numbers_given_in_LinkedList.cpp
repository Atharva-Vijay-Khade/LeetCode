

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


    // we can also do it in iterative way which is optimal in space as compared to recursion    
    // For recursion
    //             - solving this using IBH method 


public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry = 0) {
        
        // Base Case 
        if(l1==NULL&&l2==NULL) {
            
            if(carry==0)
                return NULL;
            else 
            {
                ListNode *overFlow = new ListNode();
                overFlow->next = NULL;
                overFlow->val = carry;
                return overFlow;
            }

        }
        
        // Induction Step
        ListNode *currNode = new ListNode();
        
        int l1Value = (l1!=NULL) ? l1->val : 0;
        int l2Value = (l2!=NULL) ? l2->val : 0;
        
        int sum = l1Value + l2Value + carry;
        
        currNode->val = sum%10;
        
        carry = sum/10;
        
        ListNode *l1Next;
        ListNode *l2Next;
        
        if(l1==NULL)
            l1Next = NULL;
        else 
            l1Next = l1->next;
        
        if(l2==NULL)
            l2Next = NULL;
        else 
            l2Next = l2->next;
        
        // Hypothesis
        currNode->next = addTwoNumbers(l1Next,l2Next,carry);
        
        // Induction step
        return currNode;
        
    }

};