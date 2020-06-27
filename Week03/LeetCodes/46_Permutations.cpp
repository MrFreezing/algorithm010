class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        premute(0, nums.size(), nums);
        return res;
    }

private:
    vector<vector<int>> res;
    void premute(int begin, int end , vector<int> & nums) {
        if (begin == end) {
            res.emplace_back(nums);
            return;
        }

        for (int i = begin ; i < end; i++) {
            swap(nums[i], nums[begin]);
            premute(begin + 1, end, nums);
            swap(nums[i], nums[begin]);            
        }
    }

};
