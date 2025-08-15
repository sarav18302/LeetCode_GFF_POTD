// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool compare(vector<int>& a, vector<int>& b) {
        double a1 = (1.0 * a[0]) / a[1];
        double b1 = (1.0 * b[0]) / b[1];
        return a1 > b1;
    }
class Solution {
  public:
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        // code here
        int n = val.size();
        vector<vector<int>> items(n, vector<int>(2));
        
        for(int i =0;i<n;i++)
        {
            items[i][0] = val[i];
            items[i][1] = wt[i];
        }
        sort(items.begin(), items.end(), compare);
        double res = 0.0;
        int curcap = capacity;
        for(int i =0;i<n;i++)
        {
            if(items[i][1] <= curcap)
            {
                res+=items[i][0];
                curcap-=items[i][1];
            }
            else
            {
                res+=((1.0*items[i][0]/items[i][1])*curcap);
                curcap = 0;
                break;
            }
            // cout<<res<<endl;
        }
        return res;
    }
};
