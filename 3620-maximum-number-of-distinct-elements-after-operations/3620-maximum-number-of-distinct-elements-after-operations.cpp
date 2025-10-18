class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int last = INT_MIN;
        set<int>val;
        for(int value : nums)
        {
            int p = max(last+1,value-k);
            if(p <= value+k)
            {
                val.insert(p);
                last = p;
            }
        }
        return val.size();
    }
};