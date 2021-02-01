#include <iostream>
#include <vector>
#include <string.h>



/**
 * 
 * 
 * 
 * 
 * given an input string (s) and a pattern(p), implement wildcard pattern matching with support for '?' and '*' where
 * '?' matches any single character
 * '*' matches any sequence of characters (including the empty sequence)
 * 
 * the matching should cover the entire input string (not partial)
 * 
 * 0 <= s.length() && p.length < = 2000
 */


/*
앞글자 하나씩 비교
p * 만나면 없는척
p * 다음에 있는거 찾는다 
*/

using namespace std;
class Solution{
    public:
    bool isMatch(string s, string p){
        return isMatch(&s[0], &p[0]);
    }

    // 못품...
    // https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
    // 세이브포인트처럼 전진
    bool isMatch(const char *s, const char *p){
        const char* star=NULL; // 점 주소
        const char* ss=s; // 별이 있을때 시작지점 매칭 실패시마다 ++

        while (*s){
            // *p가 ?이거나 *s *p 같으면 둘다 전진 
            if (*p=='?' || *p==*s){
                s++;
                p++;
                continue;
            } 

            // 현재 패턴문자 *이면 star에 현재 p주소 넣고 p주소 전진 및 ss에 현재 s 넣는다
            if (*p=='*'){
                star=p++;
                ss=s;
                continue;
            } 


            // 매치안되고 현재 별도 아닐때
            // 기억해뒀던 별 위치+1 주소를 p에 넣고
            // s에는 원코인 처럼 쓰는 ss를 1전진한다음에 입력 ++s
            if (star){
                p = star+1; 
                s=++ss;
                continue;
            } 

            // 별도없었고 매치되는것도없었고 세이브포인트 별인 star도 null이면 리턴 false
            return false;
        }

       // 남이있는 p 체크 별이면 계속 전진
        while (*p=='*'){p++;}

        // 남아있는게 있다 !1 == false
        // 남이있는게 없다 !0 == true
        return !*p;  
    }
};


int main(){
    Solution solution;

    cout << solution.isMatch("abcbcdfbcbcdfabcbcdf", "a*df*df") << endl;

    return 0;
}