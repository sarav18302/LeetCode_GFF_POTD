class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        set<int>window;
        map<int,int>mp;
        int l = 0;
        int maxlen = 0;
        int start = 0;
        int n = arr.size();
        for(int i =0;i<n;i++)
        {
            window.insert(arr[i]);
            mp[arr[i]]++;
            int diff = *window.rbegin()-*window.begin();
            while(diff>x && l<i)
            {
                mp[arr[l]]--;
                if(mp[arr[l]] == 0)
                window.erase(arr[l]);
                l++;
                diff = *window.rbegin()-*window.begin();
            }
            if(maxlen < (i-l+1))
            {
                maxlen = i-l+1;
                start = l;
            }
            
        }
        // cout<<l<<" "<<maxlen<<endl;
        vector<int>ans;
        for(int i = 0;i<maxlen;i++)
        ans.push_back(arr[start+i]);
        return ans;
    }
};