class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if (grid.empty() || grid[0].empty()) {
            return;
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];

                if (nr >= 0 && nr < m && nc >= 0 && 
                    nc < n && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
