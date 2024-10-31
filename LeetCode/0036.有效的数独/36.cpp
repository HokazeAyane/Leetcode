#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board){
    for(int i =0; i<9;++i){
        unordered_set<char> rows,cols,cube;
        for(int j = 0; j < 9; ++j){
            if(board[i][j] !='.' && !rows.insert(board[i][j]).second){
                return false;
            }
            if(board[j][i] !='.' && !rows.insert(board[i][j]).second){
                return false;
            }
            

            //3*3
            int rowIndex = 3*(i/3) + j/3;
            int colIndex = 3*(i%3) + j%3;
            if (board[rowIndex][colIndex] != '.' && !cube.insert(board[rowIndex][colIndex]).second) {
                return false;
            }
        }
    }
    return true;
}