class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        set<vector<int>> temp;
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                set<long long> mp;
                for(int k = j+1;k<n;k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(mp.find(fourth)!=mp.end())
                    {
                        vector<int> t = {nums[i],nums[j],nums[k], (int)(fourth)};
                        sort(t.begin(),t.end());
                        temp.insert(t);
                    }
                    mp.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(temp.begin(),temp.end());
        return ans;
    }
};