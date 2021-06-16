
// Balanced Binary Tree

// Naive : O(N^2) call height for each node and compare 

// Optimal : O(N)


// Optimal Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int height(TreeNode *root) {
        
        //base case
        if(root==NULL)
            return 0;
        
        //intermediate decision state
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int diff = abs(lh-rh);
        
        if(lh==-1||rh==-1||diff>1)
            return -1;
        else 
            return max(lh,rh) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        int h = height(root);
        
        if(h==-1)
            return false;
        else 
            return true;
        
    }
};