class Solution {
public:
    string makeGood(string s) {
        string temp = s;
        
       
        
        while(temp.size()>1)
        {
            bool flag = false;
            for(int i=0;i<temp.size()-1;i++)
            {
                if(abs(temp[i]-temp[i+1]) == 32 )
                {
                    string temp1="" ;
                    temp1+=  temp.substr(0,i);
                    temp1+=temp.substr(i+2);
                    temp=temp1;
                    
                    flag = 1;
                    break;
                }
            }
            
            
            if(!flag)
            {
                break;
            }
        }
        return temp;
        
    }
};