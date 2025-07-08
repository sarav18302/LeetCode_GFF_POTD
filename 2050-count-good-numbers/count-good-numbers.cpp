class Solution {
public:
    int M = 1e9+7;
    long long helper(long long x, long long n )
    {
        if(n ==0 || x==1)
        return 1;
        if(n%2 == 0)
        {
            return helper((x*x)%M,n/2);
        }
        else
        {
            return (x*helper((x*x)%M,n/2))%M;
        }
    }
    int countGoodNumbers(long long n) {
        long long temp = helper(20,n/2);
        return (n&1)? (temp*5)%M:temp;
    }
};