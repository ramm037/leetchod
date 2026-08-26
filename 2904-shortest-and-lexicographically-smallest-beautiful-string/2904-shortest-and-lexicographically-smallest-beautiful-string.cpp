class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // If we have more than k ones,
            // move left until we have exactly k ones
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Remove unnecessary leading zeros
            while (ones == k && s[left] == '0') {
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                // Choose shorter string
                // If same length, choose lexicographically smaller
                if (ans.empty() ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};