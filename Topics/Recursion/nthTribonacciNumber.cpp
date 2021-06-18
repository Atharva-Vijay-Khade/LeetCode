

// Nth tribonacci number 

// Naive : Using normal formula like fibonacci number 

// optimal : use dp to optimize it


// optimal solution

int dp[38];

class Solution {
public:
    
    int T(int n)
    {
        
        if(n==0||n==1)
            return n;
        if(n==2)
            return 1;
        
        if(dp[n-3]==-1)
            dp[n-3] = T(n-3);
        
        if(dp[n-2]==-1)
            dp[n-2] = T(n-2);

        if(dp[n-1]==-1)
            dp[n-1] = T(n-1);
    
         return dp[n-3]+dp[n-2]+dp[n-1]; 
        
    }
    int tribonacci(int n) {
        
        int sum = 0;
        fill(dp,dp+38,-1);
        return T(n);

    }
    
};