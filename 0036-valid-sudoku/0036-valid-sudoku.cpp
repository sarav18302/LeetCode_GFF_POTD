class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // column check
        for(int j =0;j<9;j++)
        {
            vector<int>vis(10,0);
            for(int i =0;i<9;i++)
            {
                if(board[i][j]!='.')
                {
                    char ele = board[i][j];
                    if(vis[ele -'0'] == 1)
                    return false;
                    vis[ele-'0'] = 1;
                }
            }
        }
        // row check
        for(int i =0;i<9;i++)
        {
            vector<int>vis(10,0);
            for(int j =0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    // int ele = board[i][j] - '0';
                    char ele = board[i][j];;
                    if(vis[ele-'0'] == 1)
                    return false;
                    vis[ele-'0'] = 1;
                }
            }
        }
        // grid check
        for(int i =0;i<9;i+=3)
        {
            for(int j =0;j<9;j+=3)
            {
                vector<int> vis(10,0);
                for(int x = i;x<i+3;x++)
                {
                    for(int y = j;y<j+3;y++)
                    {
                        if(board[x][y] != '.')
                        {
                            int ele = board[x][y] -'0';
                            if(vis[ele] == 1)
                            return false;
                            vis[ele] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};