class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int n = s.size();
        int open = 0,cnt = 0;;
        for(int i =0;i<n;i++)
        {
            if(s[i] == '(')
            open++;
            else
            open --;
            if(open<0)
            {
                cnt++;
                open = 0;
            }
            
            
        }
        return abs(open)+cnt;
    }
};

