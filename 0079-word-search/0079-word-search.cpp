class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int idx, int i, int j)
    {
        if(idx >= word.size())
        {
            return true;
        }
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[idx])  
        return false;
        char temp = board[i][j];
        board[i][j] = '.';
        int m = board.size(), n = board[0].size();
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        for(int k =0;k<4;k++)
        {
            int x = i+dx[k], y = j+dy[k];
            if(helper(board,word,idx+1,x,y))
                return true;
        }
    board[i][j] = temp;
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i =0;i<m;i++ )
        {
            for(int j =0;j<n;j++)
            {
                if(word[0] == board[i][j])
                {
                    if(helper(board,word,0,i,j))
                    return true;
                }
            }
        }
        return false;
    }
};