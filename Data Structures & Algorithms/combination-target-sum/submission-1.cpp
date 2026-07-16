class Solution {
public:
    void solve(vector<int>& candidates,
               int target,
               int index,
               vector<vector<int>>& ans,
               vector<int>& comb)
    {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Include
        comb.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index, ans, comb);

        // Backtrack
        comb.pop_back();

        // Exclude
        solve(candidates, target, index + 1, ans, comb);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        solve(candidates, target, 0, ans, comb);

        return ans;
    }
};