class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0; 
        int lands = 0;
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == '1') {
                    lands++;
                    clear(i, j, grid);
                }
        return lands;
    }
    void clear(int row, int col, vector<vector<char>>& grid) {
        if (grid[row][col] == '0') return;
        grid[row][col] = '0';
        if (col < grid[0].size() - 1) clear(row, col + 1, grid); //清理右边
        if (row < grid.size() - 1) clear(row + 1, col, grid); //清理下边
        if (col > 0) clear(row, col - 1, grid); //清理左边，有必要
        if (row > 0) clear(row - 1, col, grid);//清理上边，好像没必要，因为调用是从上至下的，被一个S型用例整服了
    }
};
