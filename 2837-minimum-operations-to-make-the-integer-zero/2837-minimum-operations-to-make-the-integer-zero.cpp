class Solution {
public:
    int setBits(long long n) {
        int c = 0;
        while (n > 0) {
            c += n % 2;
            n /= 2;
        }
        return c;
    }
    bool isPossibleK(int num1, int num2,int k)
    {
        long long x = 1LL*num1 - 1LL*k*num2;
        if(setBits(x) <= k && k<=x)
        return true;
        return false;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(int i =1;i<=60;i++)
        {
            if(isPossibleK(num1,num2,i)) return i;
        }
        return -1;
    }
};