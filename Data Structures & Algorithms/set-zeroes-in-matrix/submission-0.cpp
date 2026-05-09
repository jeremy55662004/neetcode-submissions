class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();       // Number of horizontal lines (Rows)
        int colCount = matrix[0].size();    // Number of vertical lines (Columns)
        
        // Since matrix[0][0] is the intersection of the first row and first column,
        // we use this extra variable specifically to track the first column.
        bool firstColZero = false;

        // Step 1: Iterate through the matrix to mark which rows/cols should be zeroed.
        for (int r = 0; r < rowCount; r++) {
            // Check if the first column (vertical line) needs to be zeroed later.
            if (matrix[r][0] == 0) {
                firstColZero = true;
            }

            // For the rest of the columns, use the first row and first column as "markers".
            // We start 'c' from 1 to avoid overwriting the 'firstColZero' logic.
            for (int c = 1; c < colCount; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0; // Mark the corresponding Row (horizontal)
                    matrix[0][c] = 0; // Mark the corresponding Column (vertical)
                }
            }
        }

        // Step 2: Use the markers to fill the interior of the matrix with zeros.
        // We iterate backwards or skip the first row/column to keep markers intact.
        for (int r = 1; r < rowCount; r++) {
            for (int c = 1; c < colCount; c++) {
                // If either the row head or the column head is 0, set current cell to 0.
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 3: Handle the first row (horizontal line).
        // If matrix[0][0] is 0, it means the first row was marked for zeroing.
        if (matrix[0][0] == 0) {
            for (int c = 0; c < colCount; c++) {
                matrix[0][c] = 0;
            }
        }

        // Step 4: Handle the first column (vertical line).
        // If our special variable is true, zero out the entire first column.
        if (firstColZero) {
            for (int r = 0; r < rowCount; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};
