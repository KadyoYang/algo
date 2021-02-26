#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전체 학생 수 n >=2 <=30
// lost >=1 <=n distinct
// reserve `` distinct
// 여벌을 가지고있는 학생이 도난당했을 수 있다. 
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = (n - lost.size());

    // 오름차순 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 중복제거
    vector<int>::iterator lostIter = lost.begin();
    vector<int>::iterator reserveIter = reserve.begin();
    while(lostIter != lost.end() && reserveIter != reserve.end()){
        if(*lostIter == *reserveIter){
            lostIter = lost.erase(lostIter);
            reserveIter = reserve.erase(reserveIter);
            // 스스로가 주인 ++ 
            answer++;
        }else if(*lostIter > *reserveIter){
            reserveIter++;
        }else{
            // lost[i] < reserve[j]
            lostIter++;
        }
    }

    for(int i = 0, j = 0; i < lost.size() && j < reserve.size(); ){
        if(abs(lost[i] - reserve[j]) == 1){
            answer++; // 주인찾음
            i++;j++;
        }else if(lost[i] - reserve[j] > 0){
            j++;
        }else{
            i++;
        }
    }


    return answer;
}
