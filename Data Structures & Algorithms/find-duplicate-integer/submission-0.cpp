class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int ,int> count;
      int maxAns = 0;
      int maxFreq =0;
      for(int i=0;i<nums.size();i++){
        count[nums[i]]++;
        maxFreq = max(maxFreq , count[nums[i]]);
      }  
      for(int i =0;i<nums.size();i++){
        if(maxFreq ==count[nums[i]]){
            maxAns = nums[i];
            break;
        }
      }
      return maxAns;
    }
};
