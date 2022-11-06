class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==0)
        {
            return s;
        }
        else if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        else
        {
            string ans = s;
            for(int i=1;i<s.size();i++)
            {
                string temp = s.substr(i) + s.substr(0,i);
                if(ans>temp)
                {
                    ans = temp;
                }
            }
            return ans;
        }
        return s;
    }
};