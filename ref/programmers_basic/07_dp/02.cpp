#include <string>
#include <string.h>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int** temp = new int*[triangle.size()];
    for(int i = 0; i < triangle.size(); ++i){
        temp[i] = new int[triangle.size()]; // 그냥 triangle.size() 넣자
        memset(temp[i], 0, sizeof(int)*triangle.size());
    }
    
    temp[0][0] = triangle[0][0];


    for(int i = 0; i < triangle.size()-1; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            // temp현재로 triangle 밑에 더해서 temp 그담에 저장
            // 해당 값보다 작으면 넣지마 
            if(temp[i+1][j] < (temp[i][j]+ triangle[i+1][j])){
                temp[i+1][j] = (temp[i][j]+ triangle[i+1][j]);
            }
            if(temp[i+1][j+1] < (temp[i][j]+ triangle[i+1][j+1])){
                temp[i+1][j+1] = (temp[i][j]+ triangle[i+1][j+1]);
            }
        }
    }

    for(int i = 0; i < triangle.size(); i++){
        if(answer < temp[triangle.size()-1][i]){
            answer = temp[triangle.size()-1][i];
        }
    }

    // 자원 반납
    for(int i = 0; i < triangle.size(); i++){
        delete[] temp[i];
    }
    delete[] temp;

    return answer;
}



