/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <vector>
#include <unordered_map>

using std::vector;

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>/**/>& board) {
        std::unordered_map<int,int> row_map[9],  col_map[9], cell_map[9];

        for (int i = 0; i < 9 ; i ++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    int num = static_cast<int>(c);
                    int cell = (i / 3) * 3 +  j / 3;

                    row_map[i][num]++;
                    col_map[j][num]++;
                    cell_map[cell][num]++;

                    if(row_map[i][num] > 1 ||
                        col_map[j][num] > 1 || 
                        cell_map[cell][num] > 1) {
                            return false;
                        }

                }
            }
        }
        return true;
    }
};
// @lc code=end

