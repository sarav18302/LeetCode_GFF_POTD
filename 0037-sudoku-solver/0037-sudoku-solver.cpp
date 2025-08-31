class Solution {
public:
    bool check(vector<vector<char>>& board,int i, int j,char val)
    {
        int row = i - i%3, col = j - j%3;
        for(int x = 0;x<9;x++) if(board[x][j] == val && x!= i) return false;
        for(int x = 0;x<9;x++) if(board[i][x] == val && x!= j) return false;
        for(int x =0;x<3;x++)
        for(int y =0;y<3;y++)
        if(board[row+x][col+y]==val) return false;
        return true;
    }
    bool helper(vector<vector<char>>& board,int i, int j)
    {
       if(i == 9) return true;
       if(j == 9) return helper(board,i+1,0);
       if(board[i][j]!='.') return helper(board,i,j+1);
       for(char a = '1';a<='9';a++)
       {
            if(check(board,i,j,a))
            {
                board[i][j] = a;
                if(helper(board,i,j+1))
                return true;
                board[i][j] = '.';
            }
       }
       return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};