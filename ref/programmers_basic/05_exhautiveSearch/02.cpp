#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
아 커서 위치도 저장을 해서 
0 1 2 
1번은 A여서 할필요가 없으면 
목표커서 2 

2로가는 빠른방법 비교해서 그걸로 해약ㅆ다
커서 이동까지 구현해야함 

뒤로가서도 맨 뒤에서 부터 해야지 

*/


int calcShortDistanceAlphabet(char destinationChar){
    if('A' == destinationChar){
        return 0;
    }else{
        int a = destinationChar - 'A'; //앞으로가거나
        int b = 'Z'-destinationChar + 1; //뒤로
        return (a >= b) ? b : a;
    }
}

int calcShortDistanceIdx(string str, int currentIdx, int targetIdx){
    // 앞으로 간다.
    int a = targetIdx - currentIdx;
    // 뒤로 간다.
    int b = currentIdx + str.length() - targetIdx;
    return (a >= b) ? b : a;
}


int solution(string name) {
    int answer = 0;
    
    int currentIdx = 0;
    int idxToUse = 0;

    while(currentIdx < name.length()){
        // 작업할 idx 찾기
        while(name[idxToUse] == 'A'){
            ++idxToUse;
        }

        // 만약 currentIdx idxToUse가 다르다 -> 'A'가 쫌 있따. 그러면 currentIdx를 옮겨야한다 
        // 옮기는 방법은 뒤로가냐 앞으로가냐. 빠른 방법으로 
        if(currentIdx != idxToUse){
            answer += calcShortDistanceIdx(name, currentIdx, idxToUse);
            currentIdx = idxToUse;
        }else{
            if(currentIdx != 0)
                answer += 1;
        }

        answer += calcShortDistanceAlphabet(name[currentIdx]);

        currentIdx++;
        idxToUse++;
    }


    return answer;
}


int main(){
    
    cout << solution("JEROEN") << endl;

    return 0;
}


