class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>mp(26,0);
        for(int i =0;i<tasks.size();i++)
        mp[tasks[i]-'A']++;
        for(int i =0;i<26;i++)
        {
            if(mp[i])
            pq.push(mp[i]);
        }
        int time = 0;
        while(!pq.empty())
        {
            vector<int> remain;
            int cycles = n+1;
            while(cycles && !pq.empty())
            {
                int max_freq= pq.top();
                pq.pop();
                if(max_freq>1)
                remain.push_back(max_freq-1);
                time++;
                cycles--;
            }
            for(auto cnt:remain)
            pq.push(cnt);
            if(pq.empty()) break;
            time+=cycles;
        }
        return time;
    }
};