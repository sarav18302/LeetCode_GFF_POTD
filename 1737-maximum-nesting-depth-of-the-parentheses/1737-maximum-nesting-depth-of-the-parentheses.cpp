class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int n = s.size();
        int in = 0;
        for(int i =0;i<n;i++)
        {
            if(s[i] == '(')
            in++;
            else if(s[i] == ')')
            in--;
            ans = max(ans,in);
        }
        return ans;
    }
};