//
// vector   #include <vector>
//
 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = { 0 };
        int col[9][9] = { 0 };
        int box[9][9] = { 0 };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0' - 1;
                if (row[i][num]) return false;
                if (col[j][num]) return false;
                if (box[3 * (i / 3) + j / 3][num]) return false;

                row[i][num] = 1;
                col[j][num] = 1;
                box[3 * (i / 3) + j / 3][num] = 1;
            }
        }

        return true;
    }
};