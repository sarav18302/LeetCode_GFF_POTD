class Solution {
  public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj, int V) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &nbr : adj[node]) {
                if (dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                    if (dist[nbr] > dist[farthestNode])
                        farthestNode = nbr;
                }
            }
        }
        return {farthestNode, dist[farthestNode]};
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V,vector<int>());
        for(auto x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        auto first = bfs(0,adj,V);
        int nodeA = first.first;
        auto second = bfs(nodeA,adj,V);
        return second.second;
    }
};
