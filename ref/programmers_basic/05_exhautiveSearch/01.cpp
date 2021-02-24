#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int supo2answers[] = {2, 1, 2, 3, 2, 4, 2, 5};
int supo3answers[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int supo2(int index){return supo2answers[index % 8];}
int supo3(int index){return supo3answers[index % 10];}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0,0,0};

    for(int i = 0; i < answers.size(); ++i){
        if(((i%5)+1)==answers[i]) score[0]++;
        if(supo2(i)==answers[i]) score[1]++;
        if(supo3(i)==answers[i]) score[2]++;
    }

    int maxVal = max(score[0], max(score[1], score[2]));
    for(int i=0; i < 3; ++i){
        if(maxVal == score[i]) answer.push_back(i+1);
    }
    return answer;
}

