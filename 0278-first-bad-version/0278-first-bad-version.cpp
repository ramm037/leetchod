// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
        int end = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            bool current = isBadVersion(mid);

            if (current && 
                (mid == 1 || !isBadVersion(mid - 1))) {
                return mid;
            } // this concept is good and it also adds the edge case of 1st one to be bad overall and the moment the mid-1 is good and mis id bad it should return mid

            if (current) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return -1;
    }
};