class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n), bit(n + 2);
        vector<int> mask(n);
        int timer = 0;

        auto add = [&](int i, int val) {
            while (i <= n) {
                bit[i] ^= val;
                i += i & -i;
            }
        };

        auto sum = [&](int i) {
            int res = 0;
            while (i > 0) {
                res ^= bit[i];
                i -= i & -i;
            }
            return res;
        };

        vector<int> parent(n, -1), order;
        stack<int> st;
        st.push(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            tin[u] = ++timer;
            order.push_back(u);

            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push(v);
            }
        }

        for (int u = 0; u < n; u++)
            up[0][u] = parent[u];

        for (int k = 1; k < LOG; k++)
            for (int u = 0; u < n; u++)
                up[k][u] = up[k - 1][up[k - 1][u]];

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            tout[u] = tin[u];

            for (int v : adj[u]) {
                if (parent[v] == u)
                    tout[u] = max(tout[u], tout[v]);
            }
        }

        for (int i = 0; i < n; i++)
            mask[i] = 1 << (s[i] - 'a');

        for (int u : order) {
            add(tin[u], mask[u]);
            add(tout[u] + 1, mask[u]);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (auto &q : queries) {
            string type;
            int u;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;
                int newMask = 1 << (c - 'a');
                int change = mask[u] ^ newMask;

                add(tin[u], change);
                add(tout[u] + 1, change);

                mask[u] = newMask;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int pathMask = sum(tin[u]) ^ sum(tin[v]) ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};