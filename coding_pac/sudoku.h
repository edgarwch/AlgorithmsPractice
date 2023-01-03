//
//  sudoku.h
//  coding_pac
//
//  Created by Edgar Wong on 04/08/2022.
//

#ifndef sudoku_h
#define sudoku_h
#include "libaray.h"

class sudoku {
private:
    bool check(vector<vector<char>>& board, int x, int y, int val)
    {
        int col_inner = x - x%3, row_inner = y - y%3;
        for(int xx =0; xx<9; xx++) if(board[xx][y] == val) return false;
        for(int yy =0; yy<9; yy++) if(board[x][yy] == val) return false;
        for (int xx = 0; xx<3; xx++)
        {
            for (int yy = 0; yy<3; yy++)
            {
                if(board[col_inner + xx][row_inner + yy] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, int x, int y)
    {
        if(x == 9) return true;
        if(y == 9) return solveSudoku(board,x+1,0);
        if (board[x][y] != '.')
        {
            return solveSudoku(board, x, y+1);
        }
        for (char val = '1'; val<= '9'; val++)
        {
            if (check(board,x,y,val))
            {
                board[x][y] = val;
                if (solveSudoku(board,x,y+1))
                {
                    return true;
                }
                board[x][y] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector>& board)
    {
        solveSudoku(board,0,0);
    }
};

#endif /* sudoku_h */
