class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
            int x = i+1;
            int y = j+1;
            while(x<matrix.size() && y<matrix[i].size()){
                if(matrix[x-1][y-1]!=matrix[x][y]){
                    return 0;
                }
                x++;
                y++;
            }
        }
        }
        return 1;
    }
};