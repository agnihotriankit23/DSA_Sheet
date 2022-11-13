class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i = s.size()-1; i>=0 ; i--)
        {
            if(s[i]!=' ')
            {
                temp.push_back(s[i]);
            }
            else{
                reverse(temp.begin(),temp.end());
                //cout<<temp<<" ";
                ans+=temp;
                ans.push_back(' ');
                temp="";
            }
        }
        int n = ans.size();
        // if(ans[n-1]==' ')
        // {
        //     ans.pop_back();
        // }
        if(temp!="")
        {
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        string ans1 = "";
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!=' ')
            {
                ans1.push_back(ans[i]);
            }
            else if((i==0 && ans[i]==' ') || i==(ans.size()-1) || ans[i+1]==' ')
            {
                
            }
            else if(i!=0 && i!=(ans.size()-1) ){
                ans1.push_back(' ');
            }
        }
        if(ans1[0]==' ')
        {
            ans1 = ans1.substr(1);
        }
        return ans1;
    }
};