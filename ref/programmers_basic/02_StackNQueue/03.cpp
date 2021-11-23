#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int currentWeight = 0;
    queue<int> bridge;
    
    for(int i = 0; i < bridge_length; ++i){
        bridge.push(0);
    }

    int truckIdx = 0;
    while(truckIdx < truck_weights.size()){
        currentWeight -= bridge.front();
        bridge.pop();
        if(weight >= currentWeight+truck_weights[truckIdx]){
            currentWeight += truck_weights[truckIdx];
            bridge.push(truck_weights[truckIdx]);
            ++truckIdx;
        }else{
            bridge.push(0);
        }
        ++answer;
    }
    answer += bridge.size();
    return answer;
}


int main(){
    vector<int> a{7, 4, 5, 6};
    solution(2, 10, a);

    return 0;
}