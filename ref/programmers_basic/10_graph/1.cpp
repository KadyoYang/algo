#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <set>
#include <string>

using namespace std;

/*
n 노드 갯수 
vertex 연결정보 2차원배열 

return 가장 먼 노드 갯수 


처음에 그래프를 만들고 써야한다고하네
인접행렬 뭐 그런거 
링크 : https://0xd00d00.github.io/2021/07/10/programmers_distance.html

인접행렬 nXn
노드는 적고 간선은 많고 밀집일때 쓰면 좋음

인접리스트
sparse 그래프 메모리효율 좋다 다만 검색에 시간이 걸린다. 

여기서는 인접리스트 써보려고함
*/



int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    // 인접리스트 구현 
    map<int, set<int>> graph;
    for(int i = 1; i <= n; ++i){
        set<int> temp;
        graph.insert(make_pair(i, temp));
    }

    for(vector<int> edgeEl : edge){
        graph.at(edgeEl[0]).insert(edgeEl[1]);
        graph.at(edgeEl[1]).insert(edgeEl[0]);
    }

    vector<unordered_set<int>> nodeLevel;
    unordered_set<int> usedNode;

    nodeLevel.push_back({1});
    usedNode.insert(1);

    while (!nodeLevel.back().empty()){
        unordered_set<int> levelToSave;
        for (int i : nodeLevel.back()){
            for(int j : graph.at(i)){
                
                if(usedNode.find(j) == usedNode.end())
                    levelToSave.insert(j);
                usedNode.insert(j);
                cout << "asd" <<endl;
            }
            // for (vector<int> vertex : edge){
            //     if (vertex[0] == i && (usedNode.find(vertex[1]) == usedNode.end())){
            //         usedNode.insert(vertex[1]);
            //         levelToSave.insert(vertex[1]);
            //     }else if (vertex[1] == i && (usedNode.find(vertex[0]) == usedNode.end())){
            //         usedNode.insert(vertex[0]);
            //         levelToSave.insert(vertex[0]);
            //     }else{}
            // }
        }


        nodeLevel.push_back(levelToSave);
    }

    nodeLevel.pop_back();
    answer = nodeLevel.back().size();
    


    return answer;
}

int main()
{

    vector<vector<int>> dat{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    int a = 6;

    int result = solution(a, dat);

    cout << "sol " << result << endl;

    return 0;
}
