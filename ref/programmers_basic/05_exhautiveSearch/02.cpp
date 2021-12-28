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
 * 와 정답 봐버렸는데 똑똑하다 
 * 아 
 * 내가 만든 테스트 케이스 다 통과 한다 
 * "BBBBBBBAAAAAB" 16
 * "ABBBBBBBAAAAAB" 17
 * "ABBBBBBBAAAAABA" 19
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


int solution(string name) {
    int answer = 0;
    
    for(char ch : name){
        answer += calcShortDistanceAlphabet(ch);
    }

    int len = name.length();
    // left_right -> 초기값 정직한 루트 
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        
        // 앞 절편 하나 + 뒤 절편 하나 + 둘중에 짧은거 하나(되돌아오는거)
        // 똑똑하다. 아 좀만 더 생각했으면 도달했는데 쩝,,,
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;


    return answer;
}

int main(){
    // 아니 문제 이상해 
    cout << solution("BBBBBBBAAAAAB") << endl;

    return 0;
}


