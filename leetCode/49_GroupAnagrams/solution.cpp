#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;



// Given an array of strings "strs"
// group the anagrams together. 
// you can return the answer in any order

// an anagram is a word or phrase formed by rearranging the letters of a differennt word or phrase.
// typically using all the original letters "exactly ones"






class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> temp;

        for(string str: strs){
            string keyStr = toAscOrder(str);
            temp[keyStr].push_back(str);    
        }

        for(auto iter = temp.begin(); iter != temp.end(); ++iter)
            result.push_back((*iter).second);
        
        return result;
    }

    string toAscOrder(string str){
        sort(str.begin(), str.end());
        return str;
    }
};

// 풀이 후기 
// sort 를 해서 k log k 시간복잡도인데
// 만약에 바이트라던지 int[26] 로 0 1 0 0 0 1 해당되는거 체킹한다음에 이것을 키로 사용하면 
// sort를 하지 않아도 되기때문에  n k 시간복잡도로 할수있다.
// n : strs.length(), k = max length of a string in strs