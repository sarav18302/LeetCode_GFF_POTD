class Solution {
public:
    //tle
    int helper(vector<int>& cardPoints, int k, int i,int j)
    {
        if(i>j || k==0)
        return 0;
        int l = cardPoints[i] + helper(cardPoints,k-1,i+1,j);
        int r = cardPoints[j] + helper(cardPoints,k-1,i,j-1);
        return max(l,r);
    }
    int maxScore(vector<int>& cardPoints, int k) {
        // return helper(cardPoints,k,0,cardPoints.size()-1);
        int n = cardPoints.size();
        int lsum = 0, rsum =0;
        for(int i =0;i<k;i++)
        lsum +=cardPoints[i];
        int j = n-1, ans = lsum;
        for(int i = k-1;i>=0;i--)
        {
            lsum -=cardPoints[i];
            rsum +=cardPoints[j];
            ans = max(ans,lsum+rsum); 
            j--;
        }
        return ans;
    }
};