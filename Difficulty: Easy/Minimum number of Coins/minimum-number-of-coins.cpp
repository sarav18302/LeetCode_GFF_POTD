// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = 10;
        vector<int>ans;
        for(int i =n-1;i>=0;i--)
        {
            if(N >= coins[i])
            {
                int cnt = N/coins[i];
                while(cnt--)
                {
                    ans.push_back(coins[i]);
                    N-=coins[i];
                }
                if(N==0)
                break;
            }
        }
        return ans;
    }
};