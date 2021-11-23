#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>





using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<int> sortedPriorities = priorities;
    sort(sortedPriorities.begin(), sortedPriorities.end());
    int sortedPrioritiesIdx = sortedPriorities.size()-1;
    
    queue<int> printerQueue;
    for(int i = 0; i < priorities.size(); ++i) printerQueue.push(i);


    int currentIdx = printerQueue.front();
    while(!printerQueue.empty() && currentIdx != location){
        currentIdx = printerQueue.front();
        int value = priorities[currentIdx];
        if(value >= sortedPriorities[sortedPrioritiesIdx]){
            answer++;
            sortedPrioritiesIdx--;
            printerQueue.pop();
        }else{
            printerQueue.push(printerQueue.front());
            printerQueue.pop();
        }

        if(currentIdx == location) break;
    }

    
    return answer;
}
