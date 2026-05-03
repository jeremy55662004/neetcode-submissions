class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        // Edge case: if the matrix is empty, return an empty result
        if (matrix.empty()) return res;

        // Initialize the four boundaries of the matrix
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        // Keep traversing while the boundaries haven't crossed each other
        while (top <= bottom && left <= right) {
            
            // 1. Traverse from left to right along the current 'top' row
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            // Move the top boundary down as this row is fully processed
            top++;

            // 2. Traverse from top to bottom along the current 'right' column
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            // Move the right boundary to the left
            right--;

            // Double-check if boundaries still valid before moving left or up
            // This prevents duplicate processing in non-square matrices
            if (top <= bottom) {
                // 3. Traverse from right to left along the current 'bottom' row
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                // Move the bottom boundary up
                bottom--;
            }

            if (left <= right) {
                // 4. Traverse from bottom to top along the current 'left' column
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                // Move the left boundary to the right
                left++;
            }
        }
        
        return res;
    }
};