class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int down = -(n-1);down<=(n+1);down++){
            for(int right = -(n-1);right<=(n+1);right++){
                int count = 0;
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        if(img1[i][j] == 1){
                            int newRow = i + down;
                            int newCol = j + right;

                            if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && img2[newRow][newCol] == 1){
                                count++;
                            }
                        }


                    }
                }
                ans = max(ans,count);
            }

        }
        return ans;
    }
};