
// Power of 2 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // Naive : take mod
        //       : keep dividing the number by 2 if we get odd number except 1 then it's not power of 2
        //       : time : O(logN)
        //       : we can solve this using both recursive and iterative versions 
        
        // Optimal : if number is power of 2 then it has only 1 bit set in it's binary
        //         : so total set bits in number should be 1
        //         : we can iterate on bits in O(logN)
        //         : to optimize this we can use brian kerningam algorithm
        
        // Most optimal : n&(n-1) should be 0 brian kerningam algorithm
        
        // recursive solution 
        
        // Base Case 

//         if(n==1)
//             return true;
        
//         if(n<=0||n%2==1)
//             return false;
        
//         return isPowerOfTwo(n/2);
        
        
        // Most optimal 
        
        return (!(n<=0)&&((n&(n-1))==0));
        
            
    }
};