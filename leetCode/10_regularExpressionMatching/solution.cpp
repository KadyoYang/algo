#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/



class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        bool result = false;
        check(sLen - 1, pLen - 1, s, p, result);
        return result;
    }
    void check(int si, int pi, string &str, string &pattern, bool &result){
        if(pattern[pi] == '*'){
            pi--;
            if(pattern[pi] == '.'){
                check(si, pi-1, str, pattern, result); // 아무것도 없을수
                while(si > 0 && pi > 0){
                    if(str[si] == pattern[pi-1]){
                        check(si, pi-1, str, pattern, result);
                    }
                    si--;
                }
            }else{
                if(str[si] == pattern[pi]){

                }
            }
        }else if(pattern[pi] == '.'){
            check(si-1, pi-1, str, pattern, result);
        }else if(str[si] == pattern[pi]){
            check(si-1, pi-1, str, pattern, result);
        }else{
            return; // 실패 언매칭
        }
        


    }
       
};



class Solution1 {
public:
    bool isMatch(string s, string p) {
        string q;
        vector<bool> is_star;
        for (auto ch: p) {
            if (ch == '*') {
                is_star[q.length()-1] = true;
            }
            else {
                q.push_back(ch);
                is_star.push_back(false);
            }
        }
        vector<bool> f,  g;
        f.push_back(true);
        for (int i = 0; i < is_star.size(); ++i) {
            f.push_back(false);
            if (is_star[i] && f[i]) {
                f[i+1] = true;
            }
        }
        for (auto ch: s) {
            g.clear();
            f.swap(g);
            f.push_back(false);
            // note that i-1 is string index
            for (int i = 1; i < g.size(); ++i) {
                f.push_back(false);
                if (f[i-1] && is_star[i-1]) {
                    f[i] = true;
                }
                if (g[i] && is_star[i-1] && (ch == q[i-1] || q[i-1] == '.')) {
                    f[i] = true;
                }
                if (g[i-1] && (ch == q[i-1] || q[i-1] == '.')) {
                    f[i] = true;
                }
            }
        }
        return f[q.length()];
    }
};

int main(){
    Solution1 sol;
    
    cout << sol.isMatch("abcabcabcabbdfdabc", ".*abc") << endl;
    return 0;
}