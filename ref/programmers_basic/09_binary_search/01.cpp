
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
동무! 려권 내라우

입국심사
기다리는 사람 수 n
심사관의 심사걸리는 시간 times vector

모든 사람이 심사를 받는데 걸리는 시간의 최솟값을 리턴 
*/

/*
동무 너무 어렵다우!
결과값이 되어야하는 시간을 (걸리는 시간) 을 기준으로 이진탐색을 해야한다.
가장 짧은시간 1 
이론상 가장 길게 걸리는 시간 (느린검사관시간 * n)

이 시간의 중간값을 주어진 시간으로 줄거다
1 ~ 60이라고 하면 중간인 
30분 을 준다고 생각해봐라

30분 주갔서

30분안에 할수있는 최대의 작업은 몇개일까 모든 검사관을 합해서 계산해보자

6명의 기다리는사람

검사관 [7, 10] 이 있다고 했을때 

30분 주어지면

30 / 7 = 4 (첫번째 조사관은 30분에 4명을 할수있다)
30 / 10 = 3 (두번째 조사관은 30분에 3명 할수있다)

합하면 7명이나 할수있네 ? 해야하는 사람은 6명인데

으이 일 너무 빨리하는거 아녀? 시간 줄여!!!

이분탐색 1 ~ 30으로 줄여서 
중앙값 (1+30)/2 로 간다 
이러면 또 6명보다 안좋은 결과가 나오겠지 그러면
어 시간이 부족하네 ? 
이진탐색 앞으로 전진
15 ~ 30 이런식으로 
간다

*/

class Solution{
    public:
    long long solution(int n, vector<int> times){
        long long answer = 0;

        sort(times.begin(), times.end());

        long long start = (times.front() * n) / times.size();
        long long end = times.back() * n;
        
        while(start <= end){
            long long mid = (start + end) / 2;
            long long count = 0;
            for(int i : times){
                count += (mid / i);
            }

            if(count < n){
                start = mid+1;
            }else{
                end = mid-1;
                answer = mid;
            }

        }
        
        return answer;
    }
    
};