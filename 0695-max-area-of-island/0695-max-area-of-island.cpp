class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int size = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                queue<pair<int, int>> q;
                if (grid[i][j] == 1) {
                    visited[i][j] =1;
                    q.push({i, j});
                    int count = 1;

                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nrow = r + drow[i];
                            int ncol = c + dcol[i];
                            if (nrow >= 0 && nrow < m && ncol >= 0 &&
                                ncol < n && grid[nrow][ncol] == 1 &&
                                visited[nrow][ncol] != 1) {
                                visited[nrow][ncol] = 1;
                                count++;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                    size = max(size, count);
                }
            }
        }
        return size;
    }
};