class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)
            return "";
       int j=0;
        for(int i=0;i<palindrome.size()/2 ;i++){
            if(palindrome[i]!='a')
                break;
            
            j++;
        }
        
        if(j>= palindrome.size()/2)
            palindrome[palindrome.size()-1]='b';
        else
            palindrome[j]='a';
        
        return palindrome;
    }
};