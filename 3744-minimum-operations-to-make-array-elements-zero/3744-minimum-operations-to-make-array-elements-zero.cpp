class Solution {
public:
    long long log4(int x)
    {
        return log2(x) / log2(4);
    }
    // long long max(long long a, long long b)
    // {
    //     return a>b?a:b;
    // }
    // long long min(long long a, long long b)
    // {
    //     return a>b?b:a;
    // }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto x: queries)
        {
            long long start = x[0], end = x[1];
            long long ops = 0;
            long long pre = 1;
            for(long long d = 1;d<17;d++)
            {
                long long curr = pre*4LL;
                long long l = max(start,pre);
                long long r = min(end,curr-1);
                if(r>=l)
                ops+=(r-l+1)*d;
                pre = curr;
            }
            ans+=(ops+1)/2;
        }
        return ans;
    }
};