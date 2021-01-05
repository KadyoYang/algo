#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tree;
        int result = 1;
        int head = 0, tail = 0, temp;
        int strSize = s.size();
        if(strSize == 0){
            return 0;
        }
        tree.insert(s[0]);
        head++;
        while(strSize > head && strSize > tail){
            if(tree.find(s[head]) == tree.end()){
                // head+1이 없다! 나아가도된다.
                tree.insert(s[head]);
                head++;
            }else{
                // 젠장 head+1이 있었다. 꼬리가 나아가자
                tree.erase(s[tail]);
                tail++;
            }
            temp = head - tail;
             result = (temp > result)? temp:result;
            // result = max(result, head-tail);
        }
        return result;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string S) {
        int S_len = S.size();
        int ptr1=0,ptr2=0;
        bool char_substr[200];
        int ans=0;
        for(int i=0;i<200;i++)   char_substr[i] =false;
        while(ptr2<S_len){
            if(char_substr[int(S[ptr2])] ){
                while(S[ptr1]!= S[ptr2]){
                    char_substr[int(S[ptr1])] = false;
                    ptr1++;
                }
                char_substr[int(S[ptr1])] = false;
                ptr1++;
            }
            char_substr[int(S[ptr2])]=true;
            ans = max(ans,ptr2-ptr1+1);
            ptr2++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.lengthOfLongestSubstring("dvdf");
    return 0;
}

/* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> tree;

        if(s.length()== 0){
            return 0;
        }
        int resultNumber = 1;
        int i = 0;
        

        while(i < s.size()){
            std::map<char, int>::iterator iter = tree.find(s.at(i));
            if(iter == tree.end()){
                tree.insert(make_pair(s.at(i), i));
            } else{
                i = iter->second + 1;
                int tempsize = tree.size();
                tree.clear();
                resultNumber = (tempsize > resultNumber) ? tempsize : resultNumber;
                continue;
            }
            i++;
        }
        resultNumber = tree.size() > resultNumber? tree.size() : resultNumber;
        return resultNumber;
    }
}; */


