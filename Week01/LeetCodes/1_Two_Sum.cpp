class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int len = nums.size();
        
        if (len > 1) {
            map<int,int> hash;
            for (int i = 0; i < len; i++) {
                if (hash.find(nums[i]) != hash.end()) {
                    ret.push_back(hash[nums[i]]);
                    ret.push_back(i);
                    return ret;        
                }
                hash[target - nums[i]] = i;
            }
        }

        return ret;
    }
};
