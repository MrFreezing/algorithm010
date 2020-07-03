class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (!rows) return false;
        int cols = matrix[0].size();
        if (!cols) return false;

        int left = 0, right = rows * cols - 1;
        while (left <= right) {
            int pivot = (left + right) / 2;
            if (matrix[pivot/cols][pivot%cols] == target)
                return true;
            else if (matrix[pivot/cols][pivot%cols] > target) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }
        
        return false;
    }
};
