class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int len = nums.size();
        for (int i=0; i < len; i++) {
            if (nums[i] == 0) 
                continue;          
            nums[j++] = nums[i];
        }

        for (; j < len; j++) {
            nums[j] = 0;
        }
    }
};
