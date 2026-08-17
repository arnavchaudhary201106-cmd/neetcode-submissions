class Solution {
public:

    bool detect(int src, int target, vector<int> adj[], int n) {

        vector<int> vis(n + 1, 0);

        vis[src] = 1;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            if (node == target) {
                return true;
            }

            for (auto adjacentNode : adj[node]) {

                if (!vis[adjacentNode]) {

                    vis[adjacentNode] = 1;
                    q.push(adjacentNode);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> adj[n + 1];

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (detect(u, v, adj, n)) {
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};