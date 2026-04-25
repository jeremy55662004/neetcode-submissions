class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int ix = 0; ix < 9; ix++) {
            for (int jx = 0; jx < 9; jx++) {
                if (board[ix][jx] == '.') {
                    continue;
                }
                int val = board[ix][jx] - '1';

                if ((rows[ix] & (1 << val)) || (cols[jx] & (1 << val))
                    || (squares[(ix/3) * 3 + (jx/3)] & (1 << val))) {
                        return false;
                    }

                    rows[ix] |= (1 << val);
                    cols[jx] |= (1 << val);
                    squares[(ix / 3) * 3 + (jx / 3)] |= (1 << val);
            }
        }
        return true;
    }
};
