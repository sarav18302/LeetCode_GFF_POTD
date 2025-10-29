class Solution {
public:
    int smallestNumber(int n) {
        int exp = log2(n)+1;
        return pow(2,exp)-1;
    }
};