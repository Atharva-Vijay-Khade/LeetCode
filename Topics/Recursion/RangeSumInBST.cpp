
// Range Sum in a BST, VVIMP

        
        // Naive : Since it's a BST we can take the inorder into an array which will be sorted, and find the sum
        //       : time : Theta(N), space : O(N)
        
        // optimal : take the inorder traversal and which ever number lies in [low, high] we take it into the sum
        //         : time : theta(N), space: O(height)
        
        // more optimal : since it's a BST so we can skip some traversals 
        //              : if root->val lies in range then we call on both sides
        //              : else if root->val is more than high then call only on left side 
        //              : else if root->val is less than low then we call onlhy on right side 
        //              : time complexity : O(N), space : O(height)
        
        
        
        //1]  optimal
        // Base Case 
//         if(root==NULL)
//             return 0;
        
//         // inorder traversal
//         int leftPossibleNodeVal = rangeSumBST(root->left,low,high);
        
//         if( ( root->val >= low ) && ( root->val <= high ) ) {
//             leftPossibleNodeVal += root->val;
//         }
        
//         int rightPossibleNodeVal = rangeSumBST(root->right,low,high);
        
//         return (leftPossibleNodeVal+rightPossibleNodeVal);
        
        // 2] most optimal
        
        if(root==NULL)
            return 0;
        
        if(root->val >= low && root->val <=high ){
            return (rangeSumBST(root->left,low,high) + root->val + rangeSumBST(root->right,low,high));
        }
        else if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        else {
            return rangeSumBST(root->left,low,high);
        }