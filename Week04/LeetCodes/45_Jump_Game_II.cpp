class Solution {
public:
    int jump(vector<int>& nums) {
        int maxpos = 0, end = 0, step = 0; 
        for (int i = 0; i < nums.size() - 1; i++) {
            if (maxpos >= i) {
                maxpos = max(maxpos, i + nums[i]);
                if ( end == i) {
                    end = maxpos;
                    step++;
                }
            }
        }

        return step;
    }
};


