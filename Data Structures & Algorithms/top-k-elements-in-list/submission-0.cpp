class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>maxHeap;
        for(auto [num,count]:mp){
            maxHeap.push({count,num});
        }
        while(k>0 && !maxHeap.empty()){
         ans.push_back(maxHeap.top().second);
         maxHeap.pop();
         k--;
        }
        return ans;
    }
};
