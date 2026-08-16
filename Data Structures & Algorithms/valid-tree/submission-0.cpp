class Solution {
public:

    bool detect(int src, vector<int>& vis, vector<vector<int>>& adj) {

        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {

                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }

                else if (parent != adjacentNode) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        if (detect(0, vis, adj)) {
            return false;
        }

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                return false;
            }
        }

        return true;
    }
};