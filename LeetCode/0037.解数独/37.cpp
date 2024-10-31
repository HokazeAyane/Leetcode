#include <vector>
using namespace std;

class Solution{
public:
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }

private:

    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j =0;j < 9; ++j){
                if(board[i][j] == '.'){
                    for(char c ='1'; c <='9'; ++c){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board)){ //递归调用 solve 函数，尝试解决下一个空格。
                            return true; //成功解决，直接返回，不会执行清空
                            }
                             board[i][j] = '.';
                        } 
                    }
                    return false;  
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board,int row, int col ,char c){
        for(int i = 0; i < 9; ++i){
            if(board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c){
                return false;
            }
        }
        return true;
    }
};