class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int sum = 0, minLen = INT_MAX;
        int l = 0, r = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum >= target) {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};