class Solution {
public:
    int findMax(vector<int>& piles)
    {
        int ans = piles[0];
        for(int i = 1;i<piles.size();i++)
        ans = max(piles[i],ans);
        return ans;
    }
    long long calTotval(vector<int>& piles, int hours)
    {
        long long val =0;
        for(int i =0;i<piles.size();i++)
        val+=ceil((double)(piles[i])/(double)(hours));
        return val;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = findMax(piles);
        cout<<l<<" "<<r<<endl;
        long long ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long val = calTotval(piles,mid);
            if(val<=h)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};