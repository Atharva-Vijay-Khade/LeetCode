

// Check Iterative version also 
// this can be solved using recursion tree method, as there are multiple choices and decisions 

class Solution {
public:
    void getCombinations(string source,int index,string &digits,vector<string> &digitsString,vector<string> &result,string curr = "") {
        
        // O(4^n) max(n) = 4; { ie : assume the loop as 4 function calls }
        
        if(index==digits.length()) {
            
            result.push_back(curr);
            return;
            
        }
        
        for(int i=0;i<source.length();i++) {
            
            string nextSource = index+1<digits.length() ? digitsString[digits[index+1]-50] : "" ;

            getCombinations(nextSource,index+1,digits,digitsString,result,curr + source[i]);
            
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0)
            return {};
        
        vector<string> digitsString(8);
        
        digitsString[0]="abc";
        digitsString[1]="def";
        digitsString[2]="ghi";
        digitsString[3]="jkl";
        digitsString[4]="mno";
        digitsString[5]="pqrs";
        digitsString[6]="tuv";
        digitsString[7]="wxyz";
        
        vector<string> result;
            
        string source = digitsString[digits[0]-50];
            
        getCombinations(source,0,digits,digitsString,result);
        
        return result;
        
    }
};