class Solution {
public:
    double profit(double a, double b)
    {
        return (a+1)/(b+1) - a/b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double total = 0;
        priority_queue<pair<double,array<int,2>>> pq;
        int n = classes.size();
        for(int i =0;i<n;i++)
        {
            auto x = classes[i];
            total+=(double)x[0]/x[1];
            pq.push({profit(x[0],x[1]),{x[0],x[1]}});
        }
        while(extraStudents--)
        {
            auto [eprofit,x] = pq.top();
            pq.pop();
            total+=eprofit;
            pq.push({profit(x[0]+1,x[1]+1),{x[0]+1,x[1]+1}});
        }
        return total/n;
    }
};