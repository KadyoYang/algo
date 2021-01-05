#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.


Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

*/


class Solution {
public:
    string multiply(string num1, string num2) {
        // ** * ** = ****
        int n1len = num1.length();
        int n2len = num2.length();
        // char res[n1len+n2len] = {0, };
        string res(n1len + n2len, 0);

        for(int i = n1len-1; i >= 0; i--){
            int carry = 0;

            for(int j = n2len-1; j >= 0; j--){
                int temp = res[i+j+1] + ((num1[i]-'0') * (num2[j]-'0')) + carry;
                carry = temp / 10;
                res[i+j+1] = temp % 10;
            }
            res[i] += carry;
        }

        size_t start = res.find_first_not_of('\0');
        if(start == string::npos) return "0";
        for(int i = start; i < res.length(); i++){
            res[i] += '0';
        }
        return res.substr(start);
    }




    string multiply1(string num1, string num2) {
    // init with 0 (number 0, not char '0')
    string sum(num1.size() + num2.size(), 0);
    

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            // don't subtract '0' when get sum[]
            int tmp = (sum[i + j + 1]) + (num1[i] - '0') * (num2[j] - '0') + carry;
            carry = tmp / 10;
            // tmp - carry * 10 is more fast than tmp % 10  
            // ( Subtract and Multiply is fast than DivRem )
            // and also don't add '0' when set sum[]
            sum[i + j + 1] = tmp - carry * 10;
        }
        sum[i] += carry;
    }
    
    // find number 0('\0'), not '0'
    size_t startpos = sum.find_first_not_of('\0');
    if (string::npos != startpos) {
        // add '0' before output
        for(int i = startpos;i<sum.size();i++)
            sum[i]+='0';
        return sum.substr(startpos);
    }
    return "0";
}
};

// 99 99 


int main(){

    Solution sol;
    /*
    int b = '0';
    int a = '2' - '0';

    cout << b << " " << a << " "<<(char)(b+3)<<endl; 

*/
    cout << sol.multiply("2", "3");
    cout << sol.multiply("123", "456");
    return 0;
}