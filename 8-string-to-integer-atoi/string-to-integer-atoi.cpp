class Solution {
public:
    int helper(string &s, int i, long ans, int sign)
    {
        if(sign*ans >= INT_MAX)
        return INT_MAX;

        if(sign*ans <= INT_MIN)
        return INT_MIN;

        if(i>=s.size() || s[i]<'0' || s[i] > '9')
        return sign*ans;

        ans = helper(s,i+1,(ans*10 + (s[i]-'0')),sign);
        return ans;
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i] == ' ')
        i++;
        int sign = 1; 
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }
        return helper(s,i,0,sign);
    }
};