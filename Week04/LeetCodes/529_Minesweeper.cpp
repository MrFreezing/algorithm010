class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (!board.size() || !board[0].size()) return board;

        char c =  board[click[0]][click[1]];
        if (c == 'M') board[click[0]][click[1]] = 'X';
        else if (c == 'E') {
            calcBlock(click[0], click[1], board);    
        } else {
            ;
        }
        return board;
    }

    void calcBlock(int row, int col, vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'E') 
            return;
        
        int Ms = 0;
        int begin_row = row ? row - 1 : row;
        int begin_col = col ? col - 1 : col;
        int end_row = row == rows - 1 ? row : row + 1;
        int end_col = col == cols - 1 ? col : col + 1;

        for (int i = begin_row; i <= end_row; i++) 
            for (int j = begin_col; j <= end_col; j++) {
                if (board[i][j] == 'M') Ms++;
            }
        
        if (Ms) {
            board[row][col] = '0' + Ms;
        } else {
            board[row][col] = 'B';
            for (int i = begin_row; i <= end_row; i++) 
                for (int j = begin_col; j <= end_col; j++) {
                    calcBlock(i, j, board);
                }
        }
    }
};
