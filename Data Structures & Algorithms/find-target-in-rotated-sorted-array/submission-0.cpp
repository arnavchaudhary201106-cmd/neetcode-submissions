class Solution {
public:

    int binarySearch(vector<int>& nums, int start, int end, int target) {

        while(start <= end) {

            int mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] < target) {
                start = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // Case 1: Already sorted
        if(nums[0] <= nums[n-1]) {

            return binarySearch(nums, 0, n-1, target);
        }

        // Find rotation point
        int i = 0;

        while(i + 1 < n && nums[i] < nums[i+1]) {
            i++;
        }

        // Search in first half
        int ans1 = binarySearch(nums, 0, i, target);

        if(ans1 != -1) {
            return ans1;
        }

        // Search in second half
        return binarySearch(nums, i+1, n-1, target);
    }
};