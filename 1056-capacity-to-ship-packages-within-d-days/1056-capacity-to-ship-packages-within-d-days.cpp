class Solution {
public:
    int findSum(vector<int>& weights)
    {
        int sum = 0;
        for(auto x: weights)
        sum+=x;
        return sum;
    }

    int findDays(vector<int>& weights, int cap)
    {
        int cnt = 0, days = 0;
        for(auto x: weights)
        {
            if(x>cap)
            return -1;
            if(x+cnt > cap)
            {
                days++;
                cnt = x;
            }
            else
            {
                cnt+=x;
            }
        }
        if(cnt >0)
        days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = findSum(weights);
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int totdays = findDays(weights,mid);
            // cout<<mid<<" "<<totdays<<endl;
            if(totdays <= days && totdays!=-1)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid +1;
            }
        }
        return ans;
    }
};