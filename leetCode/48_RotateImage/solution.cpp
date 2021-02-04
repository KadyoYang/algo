#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int maxIdx = size - 1;
        int half = (int)(size / 2);

        for(int i = 0; i < half; i++){
            for(int j = i; j < size-1-i; j++){
                // int temp = matrix[i][j];
                swap(matrix[i][j], matrix[maxIdx-j][i]);
                swap(matrix[maxIdx-j][i], matrix[maxIdx-i][maxIdx-j]);
                swap(matrix[maxIdx-i][maxIdx-j], matrix[j][maxIdx-i]);
                // 끄으으읕
            }
        }
        
    }

};