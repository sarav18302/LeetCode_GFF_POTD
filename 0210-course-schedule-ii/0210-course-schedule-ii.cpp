class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
        state[node] = 1;   // 1 = visiting

        for (int nei : adj[node]) {
            if (state[nei] == 1) return false;        // cycle found
            if (state[nei] == 0) {
                if (!dfs(nei, adj, state, order))
                    return false;
            }
        }

        state[node] = 2;   // 2 = visited
        order.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build graph: b -> a
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, adj, state, order))
                    return {};  // cycle → impossible
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
