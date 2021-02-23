#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// https://mungto.tistory.com/15
// http://www.cplusplus.com/reference/functional/less/
struct compare{
    bool operator()(vector<int>a, vector<int>b){
        return a.at(1) > b.at(1);
    }
};



int solution(vector<vector<int>> jobs) {
    int answer = 0; 
    int j = 0;
    int time = 0;

    // 실행 시작 시간 오름차순 정렬
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    while(j < jobs.size() || !pq.empty()){
        if(jobs.size() > j && time >= jobs[j][0]){
            pq.push(jobs[j++]);
            continue;
        }

        if(!pq.empty()){
            time += pq.top()[1];
            answer += time-pq.top()[0];
            pq.pop();
        }else{
            time = jobs[j][0];
        }
    }



    return answer/ jobs.size();
}