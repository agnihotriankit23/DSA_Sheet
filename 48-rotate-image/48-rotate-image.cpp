class Solution {
public:
    void rotate1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int L=0;
        int R=n-1;
        
       while(L<R){
           
           for(int i=0;i<(R-L);i++){
               int T=L;
               int B=R;
               int temp = matrix[T][L+i];
               
               matrix[T][L+i] = matrix[B-i][L];
              
               matrix[B-i][L]=matrix[B][R-i];
              
               matrix[B][R-i]=matrix[T+i][R];
              
               matrix[T+i][R]=temp;
               
              
               
           }
           L++;
           R--;
       }
        
        
        
    }
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
     
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};