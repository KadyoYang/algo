#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;



class Solution{
public:
    /*
    digits includes 2-9
    */
    vector<string> letterCombinations(string digits){
        unordered_map<char, string> letters{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}};
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        letterComb(letters, digits, "", result);
        return result;
    }
private:
    void letterComb(unordered_map<char, string> &letters, string &digits, string target, vector<string> &result){
        if(target.length() == digits.size()){
            result.push_back(target);
            return;
        }

        // digits.at(target.length());

        string letter = letters.at(digits[target.length()]);
        for(int i = 0; i < letter.size(); i ++){
            letterComb(letters, digits, (target+letter[i]), result);
        }
        return;
    }
};
int main(){
    Solution sol;
    sol.letterCombinations("23");
    return 0;
}