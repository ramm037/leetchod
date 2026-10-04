class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;
                high++;
            }

            // We cannot have a negative minimum
            if (low < 0) {
                low = 0;
            }

            // Even the maximum possibility is negative
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};