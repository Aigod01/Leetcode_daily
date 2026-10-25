
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;

                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 1;

                bool closed = true;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    if (r == 0 || c == 0 || r == m - 1 || c == n - 1)
                        closed = false;

                    for (int d = 0; d < 4; d++) {
                        int nr = r + dir[d];
                        int nc = c + dir[d + 1];

                        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                            grid[nr][nc] == 0) {
                            grid[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }

                if (closed) ans++;
            }
        }

        return ans;
    }
};
