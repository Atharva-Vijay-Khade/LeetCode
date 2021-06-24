
// Reorder List 

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
    
    ListNode* reorderListHelper(bool &isEven,ListNode *head,ListNode *&nextHalf,int &countNode) {

        
        if(countNode==0) {
            
            if(isEven) {
                
                nextHalf = head->next->next;
                head->next->next = NULL;
                return head;
                
            }
            else {
                
                nextHalf = head->next->next->next;
                head->next->next->next = head->next;
                ListNode *temp = head->next;
                head->next = head->next->next;
                temp->next = NULL;
                return head;
                
            }
            
        }
        
        ListNode *newHead = reorderListHelper(isEven,head->next,nextHalf,--countNode);
        
        head->next=nextHalf;
        ListNode *temp = nextHalf->next;
        nextHalf->next = newHead;
        nextHalf=temp;
        
        return head;
        
    }
    
    void reorderList(ListNode* head) {
        
        // Naive : take extra array and copy all elements into it 
        //       : then we can take required elements one by one 
        
        // optimal 1 : If it's ok to change the original linked list it self
        //           : count the nodes in the linked list -> theta(N)
        //           : move ahead by ceil(n/2) + 1 in the list  -> theta(N/2)
        //           : make the next of the current after moving as null
        //           : reverse the next part of the linked list  -> Theta(N/2)
        //           : and keep connecting one by one  -> Theta(N/2)
        //           : time is theta(N) space is O(1)
        
        // optimal 2 : Can we use recursion ?
        //           : then we can solve it recursively 
        //           : say a function fun() returns us the head of the ordered internal list
        //           : then the just have to change the links of the current two nodes 
        //           : time complexity will be Theta(N) {N/2 less iterations as previous}, space is theta(N/2)
        
            
        if(head == NULL)
            return;
        if(head->next == NULL)
            return;
        
        ListNode *curr = head;
        ListNode *nextHalf = NULL;
        
        // counting the nodes in the list 
        int countNode = 0;
        
        while(curr!=NULL)
        {
            countNode++;
            curr=curr->next;
        }
        
        bool isEven = ((countNode%2)==0);
        
        // reordering the list 
        countNode/=2;
        countNode--;
        reorderListHelper(isEven,head,nextHalf,countNode);
        
        return;
        
    }
    
};