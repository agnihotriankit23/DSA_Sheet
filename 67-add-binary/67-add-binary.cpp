class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i=a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(i>=0 && j>=0){
            int n1 = a[i]-'0';
            int n2 = b[j] - '0';
            cout<<n1<<" "<<n2<<endl;
            int sum = n1+n2+carry;
            if(sum==1){
                ans.push_back('1');
                carry=0;
            }else if(sum==0){
                ans.push_back('0');
                carry=0;
            }else if(sum==2){
                ans.push_back('0');
                carry=1;
            }else if(sum>2){
                 ans.push_back('1');
                carry=1;
            }
            i--;
            j--;
        }
        while(i>=0){
            int n1 = a[i]-'0';
            cout<<n1<<endl;
            int sum = n1 +carry;
            if(sum==1){
                ans.push_back('1');
                carry=0;
            }else if(sum==0){
                ans.push_back('0');
                carry=0;
            }else if(sum==2){
                ans.push_back('0');
                carry=1;
            }else if(sum>2){
                 ans.push_back('1');
                carry=1;
            }
            i--;
        }
        while(j>=0){
            int n1 = b[j]-'0';
            cout<<n1<<endl;
            int sum = n1 +carry;
            if(sum==1){
                ans.push_back('1');
                carry=0;
            }else if(sum==0){
                ans.push_back('0');
                carry=0;
            }else if(sum==2){
                ans.push_back('0');
                carry=1;
            }else if(sum>2){
                 ans.push_back('1');
                carry=1;
            }
            j--;
        }
        if(carry!=0){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};