#include <string>
#include <vector>
#include <iostream>

using namespace std;


/** 
 * 문제 이상해 !!!! 
 * "BBBBBBBAAAAAB" 의 최솟값은 16인데 
 * 아 테스트코드가 아
 * 안맞잖아 
 * 최솟값이. 아니야 ㅠ
 * 어?
 * 아 길이의 최소를 구하는걸 해보면 되겠다 
 * 
 * /
/*
아 커서 위치도 저장을 해서 
0 1 2 
1번은 A여서 할필요가 없으면 
목표커서 2 

2로가는 빠른방법 비교해서 그걸로 해약ㅆ다
커서 이동까지 구현해야함 

뒤로가서도 맨 뒤에서 부터 해야지 

*/

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


// 코드 주인 
// https://velog.io/@euneun/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A1%B0%EC%9D%B4%EC%8A%A4%ED%8B%B1-%EA%B7%B8%EB%A6%AC%EB%94%94-%ED%83%90%EC%9A%95%EB%B2%95-c
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int solution(string name) 
{
    int answer = 0;//이동 횟수
    string initial_name;
    
    for(int i = 0; i < name.size(); i++)
    {
        //주어진 이름의 길이만큼 A를 이어붙여서 초기세팅을 해줌
        initial_name += "A";
    }
    
    int current_index = 0;
    while(true)
    {   
        answer += min(name[current_index] - 'A', 'Z' - name[current_index] + 1);
        //조이스틱을 윗방향 또는 아랫방향으로 움직였을때의 최소값을 answer에 더해나감
        // 아래방향으로 움직여야될때는 한번을 더 더해줌 (왜냐면, z에서 바로가는게 아니라 a에서 z로 가는것도 한번 더 더해줘야되므로)
        initial_name[current_index] = name[current_index];
        //nowIdx에 해당하는 알파벳문자는 조이스틱으로 바꿔놓기 완료!

        if(initial_name == name)
        {
            return answer;
        }
        
        // 1. 왼쪽 이동 횟수 구하기
        int left_index = current_index;
        int left_cnt = 0; //왼쪽이동횟수
        
        while(initial_name[left_index] == name[left_index])
        {//문자가 같을 경우에는, 알파벳을 바꿀 필요가없으므로 커서를 계속 이동시킨다.
            left_index--;
            left_cnt++;
            
            // 왼쪽으로 이동시에 범위를 벗어나는 경우
            if(left_index == -1)
            {
                //첫번째 문자의 커서위치에서 왼쪽으로 이동하는경우, 마지막 문자위치로 커서를 옮겨줘야함.
                left_index = name.size()-1;
            }
        }
        
        // 2. 오른쪽 이동 횟수 구하기
        int right_index = current_index;
        int right_cnt = 0; //오른쪽이동횟수
        
        while(initial_name[right_index] == name[right_index])
        {//문자가 같을 경우에는, 알파벳을 바꿀 필요가없으므로 커서를 계속 이동시킨다.
            right_index++;
            right_cnt++;
            
            // 오른쪽으로 이동시에 범위를 벗어나는 경우
            if(right_index == name.size())
            {
                //마지막 문자의 커서위치에서 오른쪽으로 이동하는경우, 첫번째 문자위치로 커서를 옮겨줘야함
                right_index = 0;
            }      
        }
    
        // 3. 왼쪽, 오른쪽 중 횟수가 최소인 방향을 선택
        if(left_cnt < right_cnt)
        {// 왼쪽이 최소일경우
            answer += left_cnt;
            current_index = left_index;
        }
        else
        {// 오른쪽이 최소일경우
            answer += right_cnt;
            current_index = right_index;
        }
    }
}

int main(){
    // 아니 문제 이상해 
    cout << solution("BBBBBBBAAAAAB") << endl;

    return 0;
}


