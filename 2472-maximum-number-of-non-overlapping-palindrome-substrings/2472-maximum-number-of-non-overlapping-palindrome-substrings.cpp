class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;

        int i = 0;

        while (i < n) {

            bool found = false;

            // Find the earliest-ending valid palindrome
            for (int end = i + k - 1; end < n; end++) {

                for (int start = i; start <= end - k + 1; start++) {

                    if (isPalindrome(s, start, end)) {

                        ans++;

                        // Everything up to 'end' is now unavailable
                        i = end + 1;

                        found = true;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }

            if (!found) {
                break;
            }
        }

        return ans;
    }
};