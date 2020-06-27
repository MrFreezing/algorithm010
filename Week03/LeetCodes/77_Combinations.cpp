class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < 1 || k > n) return {};

        vector<vector<int>> res;
        vector<int> nums(k);
        for (int i = 0; i < k; i++) {
            nums[i] = i + 1;
        }

        deliver(nums, n, k, res);
        return res;
    }


    void deliver(vector<int>& nums, int n, int k, vector<vector<int>>& res) {
        res.push_back(nums);
        if (nums[0] == (n - k + 1)) return;

        int i = nums.size() - 1;
        while (nums[i] == n--) i--;
        for (nums[i++]++, n++; i < k; i++, n++) nums[i] = nums[i-1] + 1;
        deliver(nums, n, k, res);
    }
};

