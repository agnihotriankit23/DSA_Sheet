class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char,int> mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        mp['A']=1;
        mp['E']=1;
        mp['I']=1;
        mp['O']=1;
        mp['U']=1;
        
        vector<int> index;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                index.push_back(i);
            }
        }
        
        
        
        int start =0, end = index.size()-1;
        while(start<end){
            swap(s[index[start]],s[index[end]]);
            start++;
            end--;
        }
        
//         while(start<end)
//         {
//             cout<<s[start]<<" "<<s[end]<<endl;
//             while(mp[s[start]]!=1)
//             {
//                     start++;
//             }
//             while(mp[s[end]]!=1)
//             {
//                     end--;
//             }
            
//             char temp = s[start];
//             s[start]=s[end];
//             s[end]=temp;
//             start++;
//             end--;
//         }
        return s;
    }
};