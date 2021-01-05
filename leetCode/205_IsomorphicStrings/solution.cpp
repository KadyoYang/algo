#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if
        bool *res = new bool[s.length()]{0,};

        for(int i = 0; i < s.length(); ++i){
            if(res[i]) continue;
            char sC = s[i];
            char tC = t[i];
            for(int j = i; j < s.length(); ++j){
                if(s[j] != sC) continue;
                else if(s[j] == sC && t[j] == tC) res[j] = true;
                else return false;
            }
        }

        delete[] res;
        return true;

    }
};


class Solution1 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smp;
        unordered_map<char, char> tmp;

        for (int i = 0; i < s.size(); i++) {
            if (smp.count(s[i]) == 0) { // 없는데
                if (tmp.count(t[i]) != 0) { // 이건 있다? 똑같은거 중복으로 쭉 있다
                    return false;
                }
                smp[s[i]] = t[i];
                tmp[t[i]] = s[i];
            } else {
                if (smp[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};