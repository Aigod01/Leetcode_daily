class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            map<char, int> mpp;

            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j]))
                    mpp[board[i][j]]++;
            }

            for (auto it : mpp) {
                if (it.second > 1)
                    return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            map<char, int> mpp;

            for (int j = 0; j < 9; j++) {
                if (isdigit(board[j][i]))
                    mpp[board[j][i]]++;
            }

            for (auto it : mpp) {
                if (it.second > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                map<char, int> mpp;

                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (isdigit(board[x][y]))
                            mpp[board[x][y]]++;
                    }
                }

                for (auto it : mpp) {
                    if (it.second > 1)
                        return false;
                }
            }
        }

        return true;
    }
};