class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return j+1;
        //nums.erase(nums.begin()+j, nums.end());
    }
};