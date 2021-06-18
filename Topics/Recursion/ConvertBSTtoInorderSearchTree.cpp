    
    
    // Convert BST to inorder tree { increasing order search tree }
    
    void increasingBSTwrapper(TreeNode *root,TreeNode *&prev,TreeNode *&newRoot) {
        
        // Naive : Generate Inorder traversal list and then create a tree form that 
        //       : time : theta(N), space : theta(N) {but more than optimal}
        
        // Optimal : Traverse in Inorder way, and generate change the same tree, using previous pointer and root pointer
        
        // Base case 
        if(root==NULL)
            return;
        if(prev==NULL && root->left==NULL) {
            prev = root;
            newRoot = prev;
        }
        
        // Inorder traversal 
        increasingBSTwrapper(root->left,prev,newRoot);
        
        if(prev!=root) {
            prev->left=NULL;
            prev->right=root;
            root->left=NULL;
            prev=root;
        }
        
        increasingBSTwrapper(root->right,prev,newRoot);
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode *newRoot;
        TreeNode *prev = NULL;
        increasingBSTwrapper(root,prev,newRoot);
        return newRoot;
        
    }
      
    // Actual Solution :  Best Solution
    //     TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
    //     if (!root) return tail;
    //     TreeNode* res = increasingBST(root->left, root);
    //     root->left = NULL;
    //     root->right = increasingBST(root->right, tail);
    //     return res;
    // }