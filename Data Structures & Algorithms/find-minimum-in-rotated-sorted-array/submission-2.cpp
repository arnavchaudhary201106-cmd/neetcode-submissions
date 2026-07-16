class Solution {
public:
    int findMin(vector<int> &nums) {
        int i =0;
        int n = nums.size()-1;
        if(nums[0]>nums[n]){
       while(i+1<nums.size()&& nums[i]<nums[i+1]){
         i++;
       }
        return nums[i+1];
        }
        else{
            return nums[0];
        }
    }
};
