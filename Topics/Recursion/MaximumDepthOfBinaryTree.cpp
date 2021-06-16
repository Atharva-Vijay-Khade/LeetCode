
// Maximum Depth of binary tree

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
    int maxDepth(TreeNode* root) {
        
        // Base Case -> if root is NULL the depth is 0
        if(root==NULL)
            return 0;
        
        // Recursive subProblem
        
        int lh = maxDepth(root->left);   // get the depth of the left sub tree
        int rh = maxDepth(root->right);  // get the depth of the right sub tree
        
        return max(lh,rh)+1;             // return the maximum of left depth and right depth + 1
          
    }
};