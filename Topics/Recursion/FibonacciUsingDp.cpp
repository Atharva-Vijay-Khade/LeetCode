
// Fibonacci numbers using dp and recursion

class Solution {
    
public:
    
    int CountFibN(int dp[],int n) {
        
        if(n==0||n==1)
            return n;
        
        if(dp[n-1]==-1)
            dp[n-1] = CountFibN(dp,n-1);
        if(dp[n-2]==-1)
            dp[n-2] = CountFibN(dp,n-2);
        
        return dp[n-1] + dp[n-2];
        
    }
    
    int fib(int n) {
        
        int dp[31];
        fill(dp,dp+31,-1);
        
        return CountFibN(dp,n);
        
    }
    
};