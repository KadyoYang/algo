#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows == 0 || s.size() == 0){
            return s;
        }

        // 값이 올라가는 정도
        int amount = (numRows-1)*2;
        int strSize = s.size();
        // char * resultChar = new char[s.size()+1];
        stringstream ss;
        int charArrayIdx=0;
        int head = 0;
        for(int i = 0; i < numRows; i++){
            head=i;
            while(head < strSize){
                // result.append((const char*)s[head]);
                // resultChar[charArrayIdx++] = s[head];
                ss << s[head];
                head += amount;
                if(i > 0 && i < numRows-1 && head-(i*2) < strSize){
                    // result.append((const char*)s[head-(i*2)]);
                    // resultChar[charArrayIdx++] = s[head-(i*2)];
                    ss << s[head-(i*2)];
                }
            }
            
        }
        // string result(resultChar);
        return ss.str();
    }
};


int main(){
    Solution sol;

    cout << sol.convert("PAYPALISHIRING", 3);
    cout << sol.convert("a", 3);
    cout << sol.convert("a", 3);
    return 0;
}