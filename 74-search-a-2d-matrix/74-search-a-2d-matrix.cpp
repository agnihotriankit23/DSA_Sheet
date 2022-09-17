class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j = matrix[0].size() -1;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                i++;
            }else{
               int st=0,end=j-1;
                int mid=(st+end)/2;
                while(st<=end){
                    if(matrix[i][mid]==target){
                        return 1;
                    }else if(matrix[i][mid]>target){
                        end=mid-1;
                    }else{
                        st=mid+1;
                    }
                    mid=(st+end)/2;
                }
                return 0;
            }
        }
        return false;
    }
};