class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> heap;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            heap.push({dist, {x, y}});
            if(heap.size() > k)
                heap.pop();
        }
        vector<vector<int>> ans;
        while(!heap.empty()) {
            ans.push_back({heap.top().second.first,
                           heap.top().second.second});
            heap.pop();
        }
        return ans;
    }
};