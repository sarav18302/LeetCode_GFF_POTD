class Solution {
public:
    double myPow(double x, int n) {
       if(n == 0 || x ==1)
       return 1;
       long long t = n;
        if(n<0)
        {
            x = 1/x;
            t = abs(t);
        }
       if(n%2 ==0)
       return myPow(x*x,t/2);
       else
       return x*myPow(x*x,(t-1)/2);
    }
};