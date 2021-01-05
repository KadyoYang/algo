#include <iostream>
#include <vector>
#include <map>

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/


/*
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
**
IV = 4
IX = 9
XL = 40
XC = 90
CD = 400
CM = 900

*/
using namespace std;

// char letter[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
// int number[] = {1000, 500, 100, 50, 10, 5, 1};


// 작은거 나왔다가 큰게 나오면 4 9 빠짐 

class Solution {
public:
    int romanToInt(string s) {
        int strSize = s.length();

        map<char, int> letterMap = {
            {'M', 1000},
            {'D', 500},
            {'C', 100}, 
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };

        int result = 0;
        int head=0, rear=0;

        for(int i = 0; i < strSize; i++){
            if(i == strSize-1){
                result += (*(letterMap.find(s[i]))).second;
                break;
            }

            head = (*(letterMap.find(s[i]))).second;
            rear = (*(letterMap.find(s[i+1]))).second;

            if(head < rear){
                // 앞이 뒤보다 작다 => 4 9 조건 => 뒤엣거 - 앞에꺼 
                // 그리고 i + 2 해야대니까 i++ 한단계 점프 
                result += (rear - head);
                i++;
            }else{
                // 앞이 뒤보다 크다 => 정상 그대로 플러스
                result += head;
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    
    cout << sol.romanToInt("III")<<endl;
    cout << sol.romanToInt("IV")<<endl;
    cout << sol.romanToInt("IX")<<endl;
    cout << sol.romanToInt("LVIII")<<endl;
    cout << sol.romanToInt("MCMXCIV")<<endl;
    return 0;
}