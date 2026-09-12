class Solution {
public:

    vector<int> better(pair<long long, vector<int>>& a,
                       pair<long long, vector<int>>& b) {

        if (a.first != b.first)
            return (a.first > b.first ? a.second : b.second);

        if (lexicographical_compare(b.second.begin(), b.second.end(),
                                     a.second.begin(), a.second.end()))
            return b.second;

        return a.second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store: {left, right, weight, original_index}
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by left endpoint
        sort(arr.begin(), arr.end());

        // Store all left endpoints separately for binary search
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        // next[i] = first interval whose left > arr[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            int pos = upper_bound(
                starts.begin(),
                starts.end(),
                arr[i][1]
            ) - starts.begin();

            next[i] = pos;
        }

        // dp[i][k] = best answer starting from i,
        // when we can still choose k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Base case: no intervals remaining
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: Skip current interval
                pair<long long, vector<int>> skip = dp[i + 1][k];

                // Option 2: Take current interval
                pair<long long, vector<int>> take = dp[next[i]][k - 1];

                take.first += arr[i][2];

                take.second.push_back(arr[i][3]);

                // We need indices in increasing order
                sort(take.second.begin(), take.second.end());

                // Choose the better option
                if (skip.first > take.first) {
                    dp[i][k] = skip;
                }
                else if (take.first > skip.first) {
                    dp[i][k] = take;
                }
                else {
                    // Same score -> lexicographically smaller
                    if (lexicographical_compare(
                            take.second.begin(), take.second.end(),
                            skip.second.begin(), skip.second.end())) {

                        dp[i][k] = take;
                    }
                    else {
                        dp[i][k] = skip;
                    }
                }
            }
        }

        return dp[0][4].second;
    }
};