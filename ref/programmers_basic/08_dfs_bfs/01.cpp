#include <iostream>
#include <vector>

using namespace std;


/*
n개의 음이 아닌 정수가 있다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 한다
만약 1 1 1 1 1 로 3을 만들려면은 
- 1 + 1 + 1+ ...
+ 1 - 1 + 1 ... 5가지가 된다

사용할수있는 배열 numbers 
타겟 넘버 target 
매개변수로 주어질때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution을 짜봐라 

*/

/*
음 + - 두가지의 경우가 있으니까 
첫번째꺼 + - 하고 (+ - 에서 두가지로 갈린 재귀가 걸리고)
+ - + - (재귀 또 갈리고 하는식으로 맨 끝에서 target값 봐서 맞는거면은 방법수 하나 더하기 )

이러면 넓이 탐색인가?
*/



class Solution{
    public:
    int availableMethodSize = 0;
    int solution(vector<int> numbers, int target){
        int answer = 0;
        findAvailableMethodSize(numbers, target, 0, 0, answer);
        return answer;
    }
    
    private:
    void findAvailableMethodSize(vector<int>& numbers, int& target, int cursor, int value, int& answer){
        if(numbers.size() == cursor){
            if(target == value) 
                ++answer;
        }else{
            findAvailableMethodSize(numbers, target, cursor+1, value + numbers[cursor], answer);
            findAvailableMethodSize(numbers, target, cursor+1, value - numbers[cursor], answer);
        }
        return;
    }
};