class Solution {
public:
void dfs(int node,vector<int>&vis ,vector<vector<int>>&adj){
    vis[node]=1;
    for(auto adjacentNode :adj[node]){
        if(!vis[adjacentNode]){
            dfs(adjacentNode,vis,adj);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
vector<vector<int>>adj(n);
for(auto edge:edges){
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int>vis(n,0);
int components=0;
for(int i =0;i<n;i++){
    if(!vis[i]){
        components++;
        dfs(i,vis,adj);
    }
}
return components;
    }
};
