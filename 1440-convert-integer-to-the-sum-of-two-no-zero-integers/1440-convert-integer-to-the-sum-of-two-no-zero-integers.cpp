class Solution {
public:
    bool check(int n)
    {
        while(n>0)
        {
            int rem = n%10;
            if(rem ==0)
            return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i =1;i<n;i++)
        {
            if(check(i)&& check(n-i))
            return {i,n-i};
        }
        return {-1,-1};
    }
};