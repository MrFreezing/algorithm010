class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int len = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') continue;
                dp[i + 1][j + 1] = min(min(dp[i][j], dp[i + 1][j]), dp[i][j + 1]) + 1;
                len = max(len , dp[i + 1][j + 1]);
            }
        }

        return len * len;
    }
};
