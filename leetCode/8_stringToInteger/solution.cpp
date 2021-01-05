#include <iostream>
#include <string>



using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int strSize = str.size();
        
        int i = 0;
        int a = 1;
        int result = 0;
        
        while(i < strSize && str[i] == ' '){
            i++;
        }

        while(i < strSize && (str[i] == '-' || str[i] == '+') ){
            if(str[i] == '-'){
                a = a * -1;
            }
            i++;
        }
        
        
        while(i < strSize && (str[i] >= '0' && str[i] <= '9')){
            if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && str[i] - '0' > INT32_MAX % 10)) {
                return (a == 1) ? INT32_MAX : INT32_MIN;
            }
            result = result * 10;
            result = result + (str[i] - '0');
            i++;
        }


        return result * a;
    }
};

/* class Solution1 {
    public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (str.length() == 0) return 0;

        //Discard whitespaces in the beginning
        while (i < str.length() && str[i] == ' ')
            i++;

        // Check if optional sign if it exists
        if (i < str.length() && (str[i] == '+' || str[i] == '-'))
            sign = (str[i++] == '-') ? -1 : 1;

        // Build the result and check for overflow/underflow condition
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i++] - '0');
        }
        return result * sign;
    }
}; */



int main(){

    Solution sol;
    cout << sol.myAtoi("+");
    return 0;
}