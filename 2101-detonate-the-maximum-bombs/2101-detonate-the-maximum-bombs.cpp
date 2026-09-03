class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++) {
            queue<int> q;
            vector<int> visited(n, 0);
            q.push(i);
            int count = 1;
            visited[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                int x = bombs[curr][0];
                int y = bombs[curr][1];
                long r = bombs[curr][2];

                for (int j = 0; j < n; j++) {
                    if (visited[j] == 1)
                        continue;

                    long long x2 = bombs[j][0];
                    long long y2 = bombs[j][1];

                    long long dx = x2 - x;
                    long long dy = y2 - y;

                    long long distSq = dx * dx + dy * dy;

                    if (distSq <= r * r) {
                        visited[j] = 1;
                        q.push(j);
                        count++;
                    }
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};