class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);

        int l = 0;
        int r = 0;

        int maxLen = 0;
        int n = s.size();

        while(r < n) {

            // character already seen
            if(hash[s[r]] != -1) {

                // duplicate lies inside current window
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            // update latest index
            hash[s[r]] = r;

            // current window length
            int len = r - l + 1;

            // update answer
            maxLen = max(maxLen, len);

            r++;
        }

        return maxLen;
    }
};