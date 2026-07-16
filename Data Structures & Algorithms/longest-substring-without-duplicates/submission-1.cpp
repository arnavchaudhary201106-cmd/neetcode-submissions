class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);

        int l = 0;
        int maxSize = 0;

        for(int r = 0; r < s.size(); r++) {

            if(hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            hash[s[r]] = r;

            maxSize = max(maxSize, r - l + 1);
        }

        return maxSize;
    }
};