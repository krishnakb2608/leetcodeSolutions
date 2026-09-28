class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>row(9);
        vector<unordered_set<char>>col(9);
        vector<unordered_set<char>>boxes(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int box=(i/3)*3+j/3;
                char ch=board[i][j];
                if(row[i].count(ch)||col[j].count(ch)||boxes[box].count(ch))return false;
                row[i].insert(ch);
                col[j].insert(ch);
                boxes[box].insert(ch);
            }
        }
        return true;

    }
};