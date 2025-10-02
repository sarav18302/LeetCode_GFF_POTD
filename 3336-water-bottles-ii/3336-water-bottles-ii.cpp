class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles, empty = 0;
        while(full!=0 || empty >=numExchange)
        {
            while(empty!=0 && empty >= numExchange)
            {
                empty-=numExchange;
                full++;
                numExchange++;
            }
            empty+=full;
            ans+=full;
            full = 0;
        }
        return ans;
    }
};