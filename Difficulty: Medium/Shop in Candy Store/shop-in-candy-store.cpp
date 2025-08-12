class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int i =0, n= prices.size(), j = n-1;
        int costmin = 0;
        while(i<=j)
        {
            costmin += prices[i];
            i++;
            j-=k;
        }
        i =0,j=n-1;
        int costmax =0;
        while(i<=j)
        {
            costmax += prices[j];
            i+=k;
            j--;
        }
        return {costmin,costmax};
    }
};