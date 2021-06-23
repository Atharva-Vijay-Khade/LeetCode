

// Finding power x^n where n and x can be negative


class Solution {
public:
    
    double pow(double x,long long int n) {   
        
        // pow(x,n) = pow(x,n/2)*pow(x,n/2)   if n is even 
        //            pow(x,n/2)*pow(x,n/2)*x if n is odd
        
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        
        double temp = pow(x,n/2);
        temp*=temp;
        
        if( (n%2) == 1 )
            return temp*x;
        else 
            return temp;
    
    }
    double myPow(double x, int n) {
    
        long long int n1 = n;
        
        if(n<0){
            return (1.0/pow(x,abs(n1)));
        }
        else 
            return pow(x,n1);
        
    }
};