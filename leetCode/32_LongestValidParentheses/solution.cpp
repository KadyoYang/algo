#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int slen = s.length();
        int curRes = 0;

        if(slen == 0){
            return 0;
        }
        bool* rec = new bool[slen] {0, };


        for(int i = 0; i < slen; i++){
            if(s[i] == ')'){
                if(i-1 >= 0 && s[i-1] == '('){
                    rec[i] = true;
                    rec[i-1] = true;
                }else if(i-1 >= 0 && s[i-1] == ')'){
                    int temp = i-1;
                    while(temp >= 0 && rec[temp] ) temp--;
                    
                    if(temp >= 0 && s[temp] == '('){
                        rec[temp] = true;
                        rec[i] = true;
                    }
                }else{}
            }
        }


        for(int i = 0; i < slen; i++){
            if(rec[i]){
                curRes++;
                res = (res > curRes)? res : curRes;
            } 
            else{
                curRes = 0;
            }
        }

        delete[] rec;
        return res;
    }
};

int main(){
    Solution sol;
    sol.longestValidParentheses(")()())");
    return 0;
}