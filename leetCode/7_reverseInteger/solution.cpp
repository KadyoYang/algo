#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/
using namespace std;


class Solution {
    public:
    int reverse(int x){
        int rev = 0;
        while(x!=0){
            int pop = x % 10;
            x /= 10;
            if (rev > INT32_MAX/10 || (rev == INT32_MAX / 10 && pop > 7)) return 0;
            if (rev < INT32_MIN/10 || (rev == INT32_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


class Solution1 {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT32_MAX/10 || (rev == INT32_MAX / 10 && pop > 7)) return 0;
            if (rev < INT32_MIN/10 || (rev == INT32_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


int main(){
    Solution sol;
    
    cout << sol.reverse(120);
    return 0;
}