class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
            return 1;
        
        string str="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=97 && s[i]<=122){
                str.push_back(s[i]);
            }else if(s[i]>=65 && s[i]<=90){
                s[i]= s[i]+32;
                str.push_back(s[i]);
            }else if(s[i]>='0' && s[i]<='9'){
                str.push_back(s[i]);
            }else{
                
            }
        }
        cout<<str<<endl;
        int i=0,j=str.length()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return 0;
            }else{
                i++;
                j--;
            }
        }
        return 1;
    }
};