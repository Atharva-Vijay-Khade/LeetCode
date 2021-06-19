

class Solution {
public:
    
    
    // Naive : Useing BIT magic to generate subsets O(n*2^n)
    // Optimal: Using recursion and maintaining xor and sum
    // most optimal : checkfrom discussion
    
    
    int subsetXORSum(vector<int>& nums) 
    {
        
        int n = nums.size();
        int sum = 0;
        
        for(int curPattern=0;curPattern<pow(2,n);curPattern++){
            
            int curXOR = 0;
            for(int j=0;j<n;j++) {
                if((1<<j)&curPattern){
                    curXOR = curXOR^nums[j];
                }
            }
            sum+=curXOR;
        }
        
        return sum;
        
    }
};