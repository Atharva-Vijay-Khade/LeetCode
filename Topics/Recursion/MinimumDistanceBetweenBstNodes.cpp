    
    

    // Minimum distance between two nodes of a BST
    
        // Naive : for every node in the tree, we traverse the tree and find the difference and maintain the minimum
        //       : time : theta(N^2), space theta(N)
        
        // Optimal : Traverse in inorder way {will be sorted list} and take adjacent differences of sorted list
        //         : time : theta(N), space theta(N)
        
        
        // Inorder : first traverse the left sub tree then come to root then traverse the right sub tree
    
    
    
    
    
    
    void minDiffInBSTwrapper(TreeNode *root,int &minDiff,TreeNode *&prev) {
        
        //base case 
        
        if(root==NULL)
            return;
        
        // important part of base case to ensure that prev is correctly assigned
        if(prev==NULL && root->left==NULL)
            prev = root;
        
        
        // traversing the left sub tree making sure that prev is on correct node
        minDiffInBSTwrapper(root->left,minDiff,prev);
        
        // coming to root and then taking the minDiff, considering extra case
        if(root!=prev)
            minDiff = min(abs(root->val - prev->val),minDiff);
        prev = root;
        
        // traversing the right sub tree making sure that root was at correct node 
        minDiffInBSTwrapper(root->right,minDiff,prev);
        
        
    }
    int minDiffInBST(TreeNode* root) {
        
        int minDiff = INT_MAX;
        TreeNode *prev = NULL;
        minDiffInBSTwrapper(root,minDiff,prev);
        return minDiff;
        
    }