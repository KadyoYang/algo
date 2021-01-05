#include <iostream>
#include <vector>

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
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

3892

MMM DCCC XC II

I    1
II   2
III  3
IX   4  
X    5
XI   6
XII  7
XIII 8
IV   9 

5로 나누고 나누어 떨어지면 X 아니면 나머지만큼 I붙이기

X    10
XX   20
XXX  30
XL   40
L    50
LX   60
LXX  70
LXXX 80
XC   90


CD 400
CM 900




100 500
CD == 400

100 1000
CM == 900

800?
DCCC

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

using namespace std;


class Solution{
    public:
    string intToRoman(int num){
        string result ={};
        char letters[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        //                 1    5    10   50   100 500  1000
        // 1의 자리부터 
        int n = num;
        int i = 0;
        int temp = 0;
        while(i < 5){
            temp = n % 10; 
            if(temp == 4){

            }else if(temp == 9){

            }else if(temp < 4){

            }else{

            }

        }
        return result;
    }
};

class Solution1 {
public:
    string intToRoman(int num) 
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }
        
        return res;
    }
};