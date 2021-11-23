#include <string>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> timeCon;
    int size = progresses.size();

    for(int i = 0; i < size; ++i){
        timeCon.push((int)ceil((100-progresses[i]) / (double)speeds[i]));
    }

    int base = timeCon.front();timeCon.pop();
    int count = 1;
    while(!timeCon.empty()){
        int num = timeCon.front();timeCon.pop();
        if(base >= num){
            count++;
        }else{
            answer.push_back(count);
            count = 1;
            base = num;
        }
    }
    answer.push_back(count);

    return answer;
}

vector<int> solution2(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> timeCon;
    int size = progresses.size();

    for(int i = 0; i < size; ++i){
        timeCon.push((int)ceil((100-progresses[i]) / (double)speeds[i]));
    }

    while(!timeCon.empty()){
        int base = timeCon.front();
        timeCon.pop();
        int count = 1;
        while(!timeCon.empty() && base >= timeCon.front()){
            timeCon.pop();
            count++;
        }
        answer.push_back(count);
    }

    return answer;
}





vector<int> solution1(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 0;
    int size = progresses.size();
    int requiredTime = 0;

    for(int i = 0; i < size; ++i){
        if(progresses[i] + (speeds[i] * requiredTime) >= 100){
            count++;
        }else{
            if(count != 0){
                answer.push_back(count);
                count = 0;
            }
            
            requiredTime = ceil((100-progresses[i]) / speeds[i]);
            count++;
        }
    }
    answer.push_back(count);

    return answer;
}