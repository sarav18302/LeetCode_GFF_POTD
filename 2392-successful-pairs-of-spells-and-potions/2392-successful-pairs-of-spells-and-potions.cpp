class Solution {
public:
    int lower_bound(vector<int>& potions,int val, long long success)
    {
        int l = 0, r = potions.size()-1;
        int idx = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(1LL*potions[mid]*val >= success)
            {
                idx = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        vector<int>ans;
        for(int i = 0;i<spells.size();i++)
        {
            int idx = lower_bound(potions,spells[i],success);
            if(idx != -1)
            ans.push_back(n-idx);
            else
            ans.push_back(0);
        }
        return ans;
    }
};