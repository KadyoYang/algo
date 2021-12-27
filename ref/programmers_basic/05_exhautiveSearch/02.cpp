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
class Joystick {
private:
    int currentPos = (int)'A';
    const int MIN = (int)'A';
    const int MAX = (int)'Z';
    int calcBestDistance(int destinationChar){
        if(currentPos == destinationChar){
            return 0;
        }else{
            int a = destinationChar - currentPos; //앞으로가거나
            int b = MAX-destinationChar + 1; //뒤로
            return (a >= b) ? b : a;
        }
    }
public:
    int movePosition(char destinationChar){
        return calcBestDistance((int)destinationChar);
        
    }

};


int solution(string name) {
    int answer = 0;
    Joystick joystick;
    for(char ch : name){
        answer += joystick.movePosition(ch);
    }
    return answer += name.size()-1;
}


int main(){
    
    cout << solution("JEROEN") << endl;

    return 0;
}


