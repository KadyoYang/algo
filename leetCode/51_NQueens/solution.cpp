#include <iostream>
#include <vector>


using namespace std;

// the n-queens puzzle is the problem of placing n queens on a nXn chessboard such that no two queens attack each other
// given an integer n, return all distinct solutions to the n-queens puzzle
// each solution contains a distinct board configuration of the n-queens placement where Q & . both indicate a queen and an empty space respectively


#define BLANK '.'
#define QUEEN 'Q'

class Solution {
public:
    int max = 0;
    vector<vector<string>> solveNQueens(int n) {
        char* nBoard = new char[n*n]{BLANK, };
        vector<vector<string>> result;
        int column = 0;
        max = n;
        
        nQueenBacktrack(nBoard, column, result);

        delete[] nBoard;
        return result;
    }

private:

    void nQueenBacktrack(char* nBoard, int column, vector<vector<string>>& result){
        if(column >= max){
            

            return;
        }

        for(int rowNum = 0; rowNum < max; ++rowNum){
            if(checkCoordinate(nBoard, column, rowNum)){
                nBoard[column+(max*rowNum)] = QUEEN;
                nQueenBacktrack(nBoard, column+1, result);
                nBoard[column*max+rowNum] = BLANK;
            }
        }
        return;
    }

    bool checkCoordinate(char* nBoard, int column, int row){
        // 수평 체크 
        for(int i = column-1; i >= 0; --i){
            if(nBoard[(max*row)+i] == QUEEN)
                return false;
        }

        // 상단 체크
        for(int i = 1; ((row-i >= 0) && (column-i>= 0)); ++i){
            if(nBoard[(max*(row-i))+(column-i)] == QUEEN)
                return false;
        }

        // 하단 체크
        for(int i = 1; ((row+i < max) && (column-i>= 0)); ++i){
            if(nBoard[(max*(row+i))+(column-i)] == QUEEN)
                return false;
        }

        return true;
    }
};