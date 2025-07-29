class Solution {
public:
    int findMax(vector<int>& bloomDay)
    {
        int maxi = bloomDay[0];
        for(int i =0;i<bloomDay.size();i++)
        maxi = max(bloomDay[i],maxi);
        return maxi;
    }
    int findbloom(vector<int>& bloomDay,int val, int k)
    {
        int cnt = 0, bcnt =0;
        for(int i =0;i<bloomDay.size();i++)
        {
            
            if(bloomDay[i] <= val)
            {
                
                cnt++;
                if(cnt == k)
                {
                    bcnt++;
                    cnt =0;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        return bcnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1 , r= findMax(bloomDay);
        int n = bloomDay.size();
        int ans = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int val = findbloom(bloomDay,mid,k);
            // cout<<mid<<" "<<val<<endl;
            if(val >= m)
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