class Solution {
public:
    bool isUgly(int n) {
        if(n<0)
            return 0;
        if(n==0)
            return 0;
        set<int> s;
        
        while(n%2==0)
        {
            s.insert(2);
            n = n/2;
        }
        
        for(int i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                if(i !=2 && i!=3 && i!=5)
                {
                    return 0;
                }
                s.insert(i);
                n = n/i;
            }
        }
        
        if(n>2)
        {
            if(n !=2 && n!=3 && n!=5)
            {
                return 0;
            }
            s.insert(n);
        }
        
        // for(auto i:s)
        // {
        //     cout<<i<<" ";
        //     if(i !=2 && i!=3 && i!=5)
        //     {
        //         return 0;
        //     }
        // }
        return 1;
    }
};