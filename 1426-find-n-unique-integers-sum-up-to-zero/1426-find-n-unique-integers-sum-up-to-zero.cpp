class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr(n);
        if(n ==1)
        return {0};
        int k = 1;
        for(int i =0;i<n;i+=2)
        {
            if(i+1<n)
            {
                arr[i] = k;
                arr[i+1] = -k;
                k++;
            }
            else
            arr[i] = 0;
        }
        return arr;
    }
};