#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

/*
n 노드 갯수 
vertex 연결정보 2차원배열 

return 가장 먼 노드 갯수 

*/

unordered_set<int> getLinkedNode(vector<vector<int>>& edge, unordered_set<int>& usedNode, int target){
    unordered_set<int> result;

    for(vector<int> vertex : edge){
        if(vertex[0] == target && (usedNode.find(vertex[1]) == usedNode.end())){
            result.insert(vertex[1]);
        }else if(vertex[1] == target && (usedNode.find(vertex[0]) == usedNode.end())){
            result.insert(vertex[0]);
        }else{

        }
    }

    return result;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<unordered_set<int>> nodeLevel;
    unordered_set<int> usedNode;
    
    nodeLevel.push_back({1});
    usedNode.insert(1);


    while(!nodeLevel.back().empty()){
        unordered_set<int> levelToSave;
        for(int i : nodeLevel.back()){
            unordered_set<int> temp = getLinkedNode(edge, usedNode, i);

            for(int val : temp){
                usedNode.insert(val);
                levelToSave.insert(val);
            }
        }

        nodeLevel.push_back(levelToSave);
    }

    nodeLevel.pop_back();
    answer = nodeLevel.back().size();

    return answer;
}


int main(){

    vector<vector<int>> dat{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int a = 6;

    int result = solution(a, dat);

    cout << "sol " << result << endl;

    return 0;
}
