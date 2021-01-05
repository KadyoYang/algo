#include <iostream>
#include <string>
#include <vector>


/*
5. Longest Palindromic Substring
Medium

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0){
            return "";
        }


        int idx = 0;
        int startIdx = 0;
        int endIdx = 0;
        int stringSize = s.size();
        while(idx < stringSize){
            int x = check(idx-1, idx+1, s, stringSize);
            int xx = check(idx, idx+1, s, stringSize);
            cout << "x =" << x << " xx =" << xx << endl;
            
            if(x < xx && (xx*2) > (endIdx - startIdx+1)){
                //xx 기준으로
                startIdx = idx - (xx-1);
                endIdx = (idx+1) + (xx-1);
            
            }else if(x >= xx && (x*2 +1) > (endIdx - startIdx+1) ){
                //x 기준으로
                startIdx = idx - x;
                endIdx = idx + x;
            }else{}
            
            idx++;
        }
        cout << "startIdx=" << startIdx << " endIdx=" << endIdx << endl;
        return s.substr(startIdx, endIdx-startIdx + 1);
    }

    int check(int start, int end, string& s, int size){
        int result = 0;
        while(start >= 0 && end < size){
            if(s[start] == s[end]){
                result++;
                start--;
                end++;
            }else{
                return result;
            }
        }
        return result;
    }


};




int main(){
    string testCase1 = "bababz";
    string testCase2 = "zcabbacdi";

    // cout << testCase1.substr(0,2);
    Solution sol;

    cout << sol.longestPalindrome(testCase1) << endl;
    cout << sol.longestPalindrome(testCase2) << endl;
}





class Solution1 {
public:
    string longestPalindrome(string s) {
        int start=0; int end=0;
        if(s.size()==0)
            return "";
        else
        {
            for (int center=0;center<s.size();center++)
            {
                int len1=PaliLength(center, center, s);
                int len2=PaliLength(center, center+1, s);
                if(len1>end-start)
                {
                  start=center-len1/2;
                    end=center+len1/2;
                }
                if(len2>end-start)
                {
                    start=center+1-len2/2;
                    end=center+len2/2;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
    int PaliLength(int L, int R, string s)
    {
        int len=0;
        while (L>=0&&R<s.size())
        {
            if(s[L]==s[R])
            {
                len=R-L+1;
                L--;
                R++;
            }
            else
              break;
        }
        return len;
    }
};