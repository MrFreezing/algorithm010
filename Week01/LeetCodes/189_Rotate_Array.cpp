class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int len = nums.size();
    //     k = k % len;
    //     if (k != 0) {
    //         reserve(nums, 0, len - 1 - k);
    //         reserve(nums, len - k, len - 1);
    //         reserve(nums, 0, len -1);
    //     }
    // }

    // void reserve(vector<int>& nums, int begin, int end) {
    //     while (begin < end) {
    //         int temp = nums[begin];
    //         nums[begin++] = nums[end];
    //         nums[end--] = temp;
    //     }
    // }

    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;

        if ( k != 0) {
            for (int i = 0, start = 0; i < len; start++) {
                int next = start;
                int prev = nums[start];

                do {
                    next = (next + k) % len;
                    int temp = nums[next];
                    nums[next] = prev;
                    prev = temp;
                    i++;
                } while (next != start);
            }
        }
    }
};
