#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sol(vector<int> array, vector<int> command){
    sort(array.begin()+command[0]-1, array.begin()+command[1]);

    return array[command[0]+command[2]-2];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;


    for(vector<int> command : commands){
        answer.push_back(sol(array, command));
    }

    return answer;
}

