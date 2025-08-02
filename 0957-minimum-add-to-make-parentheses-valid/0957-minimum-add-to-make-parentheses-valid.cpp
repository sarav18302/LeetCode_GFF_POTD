class Solution {
public:
    int minAddToMakeValid(string s) {
        int in = 0;
        int n = s.size(),ans =0;
        for(int i =0;i<n;i++)
        {
            if(s[i] == '(')
            in++;
            else if(in>0)
            in--;
            else
            ans++;
        }
        return abs(in)+ans;
    }
};