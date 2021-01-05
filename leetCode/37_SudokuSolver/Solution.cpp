#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }

    void rec(vector<vector<char>>& board, int r, int c){
        if(c == 10) r++, c = 0;
        if(r == 10) return;
        if(board[r][c] == '.') return rec(board, r, c+1);
            
        
    }

    vector<int> getCandiates(){

    }

    
};


static bool R[9][9];
static bool C[9][9];
static bool B[9][9];
class Solution1
{
    public:
    bool Rec(int ind,vector<vector<char>>& a)
    {
        if(ind == 81)  return true;

        int x = ind / 9 , y = ind % 9;

        if(a[x][y] != '.')  return Rec(ind+1,a);

        for(int i = 1 ; i <= 9 ; i++)
        if(R[x][i-1] == false && C[y][i-1] == false && B[(x/3)*3 + y/3][i-1] == false)
        {
            a[x][y] = i + 48;

            R[x][i-1] = C[y][i-1] = B[(x/3)*3 + y/3][i-1] = true;

            if(Rec(ind+1,a))  return true;

            R[x][i-1] = C[y][i-1] = B[(x/3)*3 + y/3][i-1] = false;

            a[x][y] = '.';
        }

        return false;
    }
    void solve(vector<vector<char>>& a)
    {
        memset(R,false,sizeof(R));
        memset(C,false,sizeof(C));
        memset(B,false,sizeof(B));
        
        for(int i = 0 ; i < 9 ; i++)
            for(int j = 0 ; j < 9 ; j++)
                if(a[i][j] != '.')
                    R[i][a[i][j]-49] = C[j][a[i][j]-49] = B[(i/3)*3 + j/3][a[i][j]-49] = true;

        Rec(0,a);
    }
    void solveSudoku(vector<vector<char>>& a)
    {   
	    solve(a);
    }
};