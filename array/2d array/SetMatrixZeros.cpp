class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
            int col0=1;
            // m rows n cols
            int m=matrix.size(); 
            int n=matrix[0].size();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==0)
                    {
                        // hash in the matrix itself take 1st row and col for that purpose
                        // mark the ith row 
                        matrix[i][0]=0;
                        // mark the jth col 
                        if(j!=0)
                        matrix[0][j]=0;
                        else col0=0;
                    }
                }
            }
            // now iterate the matrix leaving the 0th row and col as they are hashed array
            for(int i=1;i<m;i++)
            {
                for(int j=1;j<n;j++)
                {
                    // check if ith row and jth col has been marked 0 
                    if(matrix[0][j] ==0|| matrix[i][0]==0) matrix[i][j]=0;
                }
            }
            // now handle edge cases when will 0th row which is hash array will be 0 if matrix[0][0]=0 
            if(matrix[0][0]==0)
            for(int i=0;i<n;i++) matrix[0][i]=0;
            // when will 0th col which is our hash array will be set to all zeros if col0=0
            if(col0==0)
            for(int i=0;i<m;i++) matrix[i][0]=0;

    }
};