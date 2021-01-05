#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        if(nLen == 0) return 0;
        if(hLen < nLen) return -1;
        if(hLen == nLen && !haystack.compare(needle)) return 0;
        
        for(int i = 0; i <= (hLen - nLen); i++){
            if(haystack[i] == needle[0]){
                if(!needle.compare(haystack.substr(i, nLen))) return i;
            }
        }
        return -1;
    }
};