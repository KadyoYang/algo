#include <iostream>
#include <vector>

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
using namespace std;

// backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recur(n, n, "", result);
        return result;
    }

    void recur(int left, int right, string target, vector<string> &result){
        if(left==0 && right==0){
            result.push_back(target);
            return;
        }

        if(left == right){
            recur(left-1, right, target+'(', result);
        }else{
            if(left) recur(left-1, right, target+'(', result);
            recur(left, right-1, target+')', result);
        }
        return;
    }
};

int main(){
    Solution sol;
    sol.generateParenthesis(3);
    return 0;
}