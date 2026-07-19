class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> luli;

        for (int num : nums) {
            if(luli.find(num) != luli.end()){
                return true;
            } else {
                luli.insert(num);
            }

        }
        return false;
    }
};