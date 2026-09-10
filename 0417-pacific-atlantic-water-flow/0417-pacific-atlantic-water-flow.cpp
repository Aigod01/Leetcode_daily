// This approach gives MLE
// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         vector<vector<int>>ans;

//         int m = heights.size();
//         int n = heights[0].size();

//         if(m == 1 && n ==1) return {{0,0}};

//         int drow[] = {-1,0,1,0};
//         int dcol[] = {0,1,0,-1};

//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 vector<vector<int>>visi(m,vector<int>(n,0));
//                 stack<pair<int,int>>st;
//                 st.push({i,j});
//                 visi[i][j] = 1;
//                 bool pacific = false;
//                 bool atlantic = false;

//                 while(!st.empty()){

//                     int r = st.top().first;
//                     int c = st.top().second;
//                     if((r == 0 ) || (c == 0)) pacific = true;
//                     if((c == n-1) || (r == m-1)) atlantic = true;
//                     st.pop();

//                     for(int i =0;i<4;i++){
//                         int nrow = r + drow[i];
//                         int ncol = c + dcol[i];
                        
//                         if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
//                             if(heights[nrow][ncol] <= heights[r][c] && visi[nrow][ncol]!=1){
//                                 st.push({nrow,ncol});
//                                 visi[nrow][ncol] = 1;
//                             }
//                         }

//                     }
//                 }
//                 if(pacific == true && atlantic == true) ans.push_back({i,j});

//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int m, n;
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& heights, 
             vector<vector<int>>& visi, int r, int c) {
        
        visi[r][c] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < m && 
               ncol >= 0 && ncol < n &&
               !visi[nrow][ncol] &&
               heights[nrow][ncol] >= heights[r][c]) {
                
                dfs(heights, visi, nrow, ncol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }

        for(int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

