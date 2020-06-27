class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return {};

        sort(nums.begin(), nums.end());
        premuteUnique(0, nums.size(), nums);
        return res;
    }
private:
    vector<vector<int>> res;
    void premuteUnique(int begin, int end, vector<int> & nums) {
        if (begin == end) {
            if (find(res.begin(), res.end(), nums) ==  res.end())
                res.emplace_back(nums);
            return;
        }
        
        for (int i = begin; i < end; i++) { 
            if (i > begin && nums[i] == nums[i - 1]) {
                continue;
            } else {
                swap(nums[i], nums[begin]);
                premuteUnique(begin + 1, end, nums);
                swap(nums[i], nums[begin]);
            }
        }
    }
};
