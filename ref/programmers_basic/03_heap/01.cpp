#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {

    // less = max heap, greater = min heap
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int answer = 0;
    int currentSize = scoville.size();

    while(pq.top() < K){
        if(currentSize == 1) return -1;
        int temp = pq.top(); pq.pop();
        temp += (pq.top()*2); pq.pop();
        pq.push(temp);
        ++answer;
        --currentSize;
    }

    return answer;
}