class Solution {
    private:
      bool solve(vector<vector<char>>&board)
      {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                           if(solve(board)==true)  return true;
                            else  board[i][j]='.';
                        }
                    }
                    // empty mila but solve ni ho paya 1-9 se
                    return false;
                }
            }
        }
        // empty hi ni mila
        return true;
      }
      bool isValid(vector<vector<char>>&board,int row,int col,char ch)
      {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch) return false;
            if(board[i][col]==ch) return false;
            if(board[3 * (row/3) + i/3][3* (col/3) +i%3]==ch) return false;
        }
        return true;
      }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};