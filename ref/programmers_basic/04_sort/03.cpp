#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
1 2 3 4 8 8 8 8 8 8 일때 
h index 는 6이어야하지 

*/


int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());
    int i = 0;
    for(i = 0; i < citations.size(); ++i){
        if(citations[i] <= citations.size() - i){
            answer = citations[i];
        }else{
            break;
        }
    }

    while(i < citations.size()){
        if((answer+1) <= citations[i] && (answer+1) <= citations.size()-i){
            answer++;
        }else{
            break;
        }
        

    }
    return answer;
}