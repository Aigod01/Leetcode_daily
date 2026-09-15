class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int result = -1e9;
       
        if(k ==1) return matrix[0][0];
        vector<vector<int>>visited(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({matrix[0][0],{0,0}});
        visited[0][0] = 1;

        int drow[]= {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        int count = 1;

        while(!pq.empty()){
            if(count == k) return pq.top().first;
            count++;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            for(int i =0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 &&nrow<n && ncol>=0 && ncol<n && visited[nrow][ncol]!=1){
                    pq.push({matrix[nrow][ncol],{nrow,ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return 0;

    }
};