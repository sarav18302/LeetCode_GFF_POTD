class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int xorVal = 0;
        int n = arr.size();
        for (int i=0; i<n; i++) {
            xorVal = arr[i] ^ xorVal;
        }
         xorVal &= -xorVal;
         vector<int> ans(2,0);
         for(int i =0;i<n;i++)
         {
             if((arr[i] & xorVal) == 0)
             ans[0] = ans[0] ^arr[i];
             else
             ans[1] = ans[1] ^arr[i];
         }
         if(ans[0] < ans[1]) swap(ans[0],ans[1]);
         return ans;
    }
};