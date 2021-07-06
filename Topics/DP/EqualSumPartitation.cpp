bool dp[202][int(1e4+2)];

class Solution {
public:
    
    bool SubSetSum(vector<int>& nums,int sum,int n) {
        
        // writing recursive code and then memoize it and then go for tabulation -> method 1
        // this is similar to knapsack problem where given array is weight array 
        
        // and value arrays are ignored, and this problem can be solved using tabular 
        // derivation of the knapsack problem -> method 2
        
        
        // Method -> 1
            
//         // Base Case 
//         if(sum==0)
//             return true;
//         if(n==0)
//             return false;
        
//         if(dp[n][sum]!=-1)
//             return dp[n][sum];
        
//         // Choice Diagram
//         if(nums[n-1]<=sum)
//            return dp[n][sum] = (SubSetSum(nums,sum-nums[n-1],n-1)||SubSetSum(nums,sum,n-1));
//         else 
//             return dp[n][sum] = SubSetSum(nums,sum,n-1);
        
        
        // Method -> 2 { Observed that it's knapsack variation}
        
        // initializtion of method 2
        for(int j=0;j<sum+1;j++)
            dp[0][j]=false;
        for(int i=0;i<nums.size()+1;i++)
            dp[i][0]=true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
    bool canPartition(vector<int>& nums) {
        
        // this is the question on equal sum partitation 
        // means there are two subsets/paritation which has equal sum in the array
        // also there sum add to total array sum
        // thus since those two subset have equal sum the array sum should be even 
        // for the partitaion to exist
        
        // if the sum is even we simply need to check if there exist a subset 
        // with sum equal to sum/2 in the array or not 
        
        // for method 1, memoization
        // memset(dp,-1,sizeof(dp));

        
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(sum%2 != 0) 
            return false;
        else
            return SubSetSum(nums,sum/2,nums.size());
        
    }
};