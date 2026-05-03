class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r) {
            for (int ix = 0; ix < r - l; ix++) {
                int top = l;
                int bottom = r;

                //save the topleft
                int topLeft = matrix[top][l + ix];

                //move bottom left into top left
                matrix[top][l + ix] = matrix[bottom - ix][l];

                //move bottom right into bottom left
                matrix[bottom - ix][l] = matrix[bottom][r - ix];

                // move top right into bottom right
                matrix[bottom][r - ix] = matrix[top + ix][r];

                // move top left into top right
                matrix[top + ix][r] = topLeft;
            }
            r--;
            l++;
        } 
    }
};
