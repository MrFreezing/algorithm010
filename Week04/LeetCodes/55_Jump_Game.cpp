// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int k = 0;
//         for (int i = 0; i < nums.size() && k < nums.size(); i++) {
//             if (i > k) return false;
//             k = max(k, i + nums[i]);
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        for (int i = last - 1; i >= 0; i--) {
            if (nums[i] + i >= last) {
                last = i;
            }
        }

        return last <= 0;
    }
};
