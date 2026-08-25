class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int x = k;

while(seen.count(x)) {
    x += k;
}

return x;

    }
};