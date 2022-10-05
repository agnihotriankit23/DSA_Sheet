class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
   int num = columnNumber;
        num =num-1;
    
    while(num >= 26)
    {
        int temp = num % 26 ;
        s+=char(temp +65);
        num = num / 26-1;
    }
    
     if(num <= 26)
    s+=char(num+65);
     
    for(int i = 0 ; i < s.size()/2 ; i++)
       swap(s[i],s[s.size()-1-i]);
    
    return s;
}
};