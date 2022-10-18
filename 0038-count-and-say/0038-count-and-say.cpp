class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        vector<string> v(n+2);
        v[1]=s;
        v[2]= "11";
        for(int i = 3 ;i<=n; i++){
            //cout<<"Heloo\n";
            string prv = v[i-1];
            //cout<<prv<<" ";
            string str = "";
            int ind =0;
            while(ind<prv.size()){
                int cnt = 0;
                char val = prv[ind];
                while(ind<prv.size() && prv[ind]==val){
                    ind++;
                    cnt++;
                }
                str.push_back(char(cnt+'0'));
                str.push_back(val);
            }
            v[i]=str;
        }
        return v[n];
    }
}; 