class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return 0;
        int n = grid[0].size();
        
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;

        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <= n; j++) 
                dp[j] = min(dp[j - 1], dp[j]) + grid[i - 1][j - 1];

        return dp[n];
    }
};
