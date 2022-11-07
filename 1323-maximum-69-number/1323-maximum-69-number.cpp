class Solution {
public:
    int maximum69Number (int num) {
        int temp = 0;
        string s = to_string(num);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        for(int i = 0;i<s.size();i++)
        {
            temp=temp*10;
            temp+= int(s[i]-'0');
        }
        
        return temp;
    }
};