#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <string>

using namespace std;

#define CAL_BOX_NUM(ROW, COL) ( (COL/3) + ((ROW/3)*3) )

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 3번의 반복말고 한번의 반복먄으로 해결하자

        // to know what first point of box is
        /*
        행  렬
        0~2 0~2 0
        0~2 3~5 1
        0~2 6~8 2

        3~5 0~2 3
        3~5 3~5 4
        3~5 6~8 5

        6~8 0~2 6
        6~8 3~5 7
        6~8 6~8 8
        (렬/3) + ((행/3)*3) == 박스번호
        */
        char c = '.';
        
        // rows
        // unordered_map<char, bool> rows[9];
        unordered_set<char> rows[9];

        // columns
        // unordered_map<char, bool> columns[9];
        unordered_set<char> columns[9];

        // boxes
        // unordered_map<char, bool> boxes[9];
        unordered_set<char> boxes[9];

        
        for(int row = 0; row < 9; row++){
            for(int column = 0; column < 9; column++){
                c = (board[row])[column];
                if(c == '.') continue;
                else if(
                    rows[row].find(c) != rows[row].end() ||
                    columns[column].find(c) != columns[column].end() ||
                    boxes[CAL_BOX_NUM(row, column)].find(c) != boxes[CAL_BOX_NUM(row, column)].end()
                    ) return false;
                else{
                    rows[row].insert(c);
                    columns[column].insert(c);
                    boxes[CAL_BOX_NUM(row, column)].insert(c);
                }
            }
        }
        return true;
    }
    
};




class Solutionx {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int grid[3][9][10] = {0,};
        int temp = 0;

        for(int row = 0; row < 9; row++){
            for(int column = 0; column < 9; column++){
                if(board[row][column] == '.') continue;
                temp = board[row][column] - '0';
                
                if(grid[0][row][temp]++ == 0 && 
                    grid[1][column][temp]++ == 0 &&
                    grid[2][CAL_BOX_NUM(row,column)][temp]++ == 0
                )continue;
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
};


class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int grid[3][9][10] = {0,};
        int temp = 0;

        for(int row = 0; row < 9; row++){
            for(int column = 0; column < 9; column++){
                if(board[row][column] == '.') {}
                else{
                    temp = board[row][column] - '0';
                    if(grid[0][row][temp]++ > 0) return false; 
                    if(grid[1][column][temp]++ > 0) return false;
                    if(grid[2][CAL_BOX_NUM(row,column)][temp]++ > 0) return false;

                }  
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int grid[3][9][10] = {0,};
        int temp = 0;

        for(int row = 0; row < 9; row++){
            for(int column = 0; column < 9; column++){
                temp = board[row][column] - '0';
                
                if(temp < 0 || temp > 10) {}
                else{      
                    if(grid[0][row][temp]++ > 0) return false; 
                    if(grid[1][column][temp]++ > 0) return false;
                    if(grid[2][CAL_BOX_NUM(row,column)][temp]++ > 0) return false;
                }  
            }
        }
        return true;
    }
};


