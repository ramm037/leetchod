class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);

            // Start a new subarray with only nums[i]
            int rem = num % k;
            next[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newRem = (r * rem) % k;
                next[newRem] += dp[r];
            }

            // All subarrays ending here become previous
            // subarrays for the next iteration.
            dp = next;

            // Add them to the global answer
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};