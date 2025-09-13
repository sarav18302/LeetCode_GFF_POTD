class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(),x.end());
        sort(y.begin(), y.end());
        int hCount = 1, vCount = 1;
        int i = x.size()-1, j = y.size()-1;
        int cost = 0;
        while(i>=0 && j>=0)
        {
            if(x[i]>=y[j])
            {
                cost+=(hCount*x[i]);
                vCount++;
                i--;
            }
            else
            {
                cost+=(vCount*y[j]);
                hCount++;
                j--;
            }
        }
        while(i>=0)
        {
            cost+=(hCount*x[i]);
            vCount++;
            i--;
        }
        while(j>=0)
        {
            cost+=(vCount*y[j]);
            hCount++;
            j--;
        }
        return cost;
    }
};
