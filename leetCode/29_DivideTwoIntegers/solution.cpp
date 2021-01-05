#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        bool plus = true;
        long a = dividend;
        long b = divisor;
        if(!dividend) return result;
        
        if(a < 0){
            plus = !plus;
            a = -a;
        }
        if(b < 0){
            plus = !plus;
            b = -b;
        }

        a -= b;
        while(a > 0){
            result++;
            a -= b;
        }


        if(!plus){
            result = -result;
        }
        return result;
    }
};