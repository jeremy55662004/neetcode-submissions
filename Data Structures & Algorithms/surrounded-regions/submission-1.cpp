class Solution {
private:
    int ROWS, COLS;

    // DFS helper function to rescue connected 'O' cells from the borders
    void capture(vector<vector<char>>& board, int r, int c) {
        // Base case: Out of bounds, or the cell is not 'O' (could be 'X' or already marked 'T')
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != 'O') {
            return;
        }

        // Mark this surviving 'O' cell as 'T' (Temporary)
        board[r][c] = 'T';

        // Traverse all 4 adjacent neighbors (down, up, right, left)
        capture(board, r + 1, c);
        capture(board, r - 1, c);
        capture(board, r, c + 1);
        capture(board, r, c - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        ROWS = board.size();
        COLS = board[0].size();

        // Step 1: Scan the left and right borders
        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') capture(board, r, 0);
            if (board[r][COLS - 1] == 'O') capture(board, r, COLS - 1);
        }

        // Step 2: Scan the top and bottom borders
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') capture(board, 0, c);
            if (board[ROWS - 1][c] == 'O') capture(board, ROWS - 1, c);
        }

        // Step 3: Final cleanup - Flip 'O' to 'X', and restore 'T' back to 'O'
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Enclosed 'O' gets captured
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // Surviving 'T' restores to 'O'
                }
            }
        }
    }
};