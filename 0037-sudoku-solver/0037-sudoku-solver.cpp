class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char x)
    {
        for(int k =0;k<9;k++) if(board[i][k] == x) return false;
        for(int k = 0;k<9;k++) if(board[k][j] == x) return false;
        int row = i- i%3, col = j-j%3;
        for(int l =0;l<3;l++)
        {
            for(int r = 0;r<3;r++)
            {
                if(board[row+l][col+r] ==x )
                return false; 
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int i, int j)
    {
        if(j==9) return helper(board,i+1,0);
        if(i == 9) return true;
        if(board[i][j] !='.') return helper(board,i,j+1);

        for(char x = '1';x<='9';x++)
        {
            if(check(board,i,j,x))
            {
                board[i][j] = x;
                if(helper(board, i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};