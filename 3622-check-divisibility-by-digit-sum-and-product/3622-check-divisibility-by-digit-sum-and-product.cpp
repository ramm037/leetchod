class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;
        int digit = 0;

        while (n > 0) {
            digit = n % 10;

            sum = sum + digit;
            product = product * digit;

            n = n / 10;
        }

        return original % (sum + product) == 0;
    }
};