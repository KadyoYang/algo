#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
/*
  Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
  */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        deque<int> intdeque;
        
        // 숫자추출
        int number;
        while(x != 0){
            number = x%10;
            x /=10;
            intdeque.push_back(number);
        }
        
        for(int i = 0; i < intdeque.size(); i++){

        }

        // 숫자검증
        if(intdeque.size() % 2 == 0){
            // 짝수
            while(intdeque.empty() == false){
            if(intdeque.front() != intdeque.back()){
                return false;
            }
            intdeque.pop_back();
            intdeque.pop_front();
        }
        }else{
            while(intdeque.size() != 1){
            if(intdeque.front() != intdeque.back()){
                return false;
            }
            intdeque.pop_back();
            intdeque.pop_front();
        }
        }
        
        return true;
    }
};

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long x_r = 0, xt = x;
        while ( xt > 0 ) {
            x_r = x_r * 10 + xt % 10;
            xt /= 10;
        }
        return ( (static_cast<int>(x_r)) == x);
         
    }
};


int main(){
    Solution sol;
    int tc1 = 121;
    int tc2 = -121;
    int tc3 = 10;
    int tc4 = 1331;
    int tc5 = 2322;

    cout << sol.isPalindrome(tc1) << endl;
    cout << sol.isPalindrome(tc2) << endl;
    cout << sol.isPalindrome(tc3) << endl;
    cout << sol.isPalindrome(tc4) << endl;
    cout << sol.isPalindrome(tc5) << endl;
    return 0;
}