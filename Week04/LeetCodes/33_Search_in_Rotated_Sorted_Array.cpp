class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pivot = (left + right) / 2;

            if (target == nums[pivot]) return pivot;
            else if (nums[pivot] < nums[right]) { //右侧有序
                if (target > nums[pivot] && target <= nums[right]) {//在有序区
                    left = pivot + 1;
                } else {
                    right = pivot - 1;
                }
            } else { //左侧有序
                if (target >= nums[left] && target < nums[pivot]) {
                    right = pivot - 1;
                } else {
                    left = pivot + 1;
                }
            }

        }
        return  -1;
    }
};
