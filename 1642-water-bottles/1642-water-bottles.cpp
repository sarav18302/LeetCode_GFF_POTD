class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles,empty = 0;
        while(full !=0)
        {
            //drinking
            ans+=full;
            empty += full;
            full = 0;

            //exchange
            int n = empty/numExchange;
            full += n;
            empty = empty - (n*numExchange);
            // cout<<full<<" "<<empty<<endl;
        }
        return ans;
    }
};