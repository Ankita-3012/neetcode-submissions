class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, sq[9] = {0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                int dig = board[i][j] - '1';

                if((row[i] & (1<<dig)) || (col[j] & (1<<dig)) || (sq[(i/3)*3 + (j/3)] &(1<<dig))) return false;

                row[i] |= (1<<dig);
                col[j] |= (1<<dig);
                sq[(i/3)*3 + (j/3)] |= (1<<dig);

            }
        }
        return true;
    }
};
