class Solution {
public:
    int findMin(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums[0] < nums[nums.size() - 1] ) return nums[0];

        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if (left + 1 == right) return nums[right];
            int mid = (left + right) / 2;
            if (nums[mid - 1] > nums[mid]) return nums[mid];
            else if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            else if (nums[mid] < nums[right]) {//右侧有序
                right = mid - 1;
            } else {//左侧有序
                left = mid + 1;
            }
        }

        return 0;
        
    }
};
