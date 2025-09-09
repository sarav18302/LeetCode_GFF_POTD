class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        int n = mices.size();
        if(n == 1)
        return abs(mices[0]-holes[0]);
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        int ans = -1e9;
        for(int i =0;i<n;i++)
        {
            ans = max(ans,abs(mices[i] - holes[i]));
        }
        return ans;
        
    }
};