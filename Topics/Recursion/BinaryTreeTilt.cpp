

//Binary Tree Tilt 

// Naive : O(N^2) - top down approach for each node calculate left sub tree node sum and same for right and maintian sum
// Optimal : O(N) - bottom up approach, maintian sum and node sum simultaneously

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
    
    int GetSumOfTilts(TreeNode *root,int &sum) {
        
        // Base Case 
        
        if(root==NULL)
            return 0;
        
        // Intermediate Decision State
        
        int leftSubTreeNodeSum = GetSumOfTilts(root->left,sum);
        int rightSubTreeNodeSum = GetSumOfTilts(root->right,sum);
        
        sum = sum + abs(leftSubTreeNodeSum-rightSubTreeNodeSum);
        
        return (leftSubTreeNodeSum+rightSubTreeNodeSum+root->val);
        
    }
    int findTilt(TreeNode* root) {
        
        int sum = 0;
        GetSumOfTilts(root,sum);
        return sum;
    
    }
};