class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
         if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
         if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
    
        long cnt = 0;
        bool sign = true;
        if(dividend >0 && divisor <0) sign = false;
        if(dividend < 0 && divisor >0) sign = false;
        long  n = labs(dividend);
        long  d = labs(divisor);
        while(n >=d)
        {
            int i =0;
            while(n >= (d<<(i+1)))
            i++;
            n -= (d*(1<<i));
            // cout<<(1<<i)<<endl;
            cnt+=(1<<i);
        }
        if(cnt == (1<<31) && sign)
        return INT_MAX;
        if(cnt == (1<<31) && !sign)
        return INT_MIN;

        return sign? cnt: -cnt;
    }
};