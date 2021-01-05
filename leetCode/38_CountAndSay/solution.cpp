#include <iostream>
#include <vector>
#include <string>

#define MAX=30

using namespace std;
 // namespace std;


// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++) {
            result = itos(result);
        }
        return result;
    }

    string recur(int n, int& target, string s){
        if(n == target){
            return s;
        }
        return recur(++n, target, itos(s));


    }

    string itos(string s){
        string result = "";
        int i = 0;
    
        while(i < s.length()){
            int j = i;
            while(s[i] == s[j]) j++; // 0 3    j가 다른 index에서 끝남

            result += to_string(j - i);
            result += s[i];
            i = j;   
        }

        return result;
    }
};


int main(){
    Solution sol;
    cout << sol.countAndSay(4) << endl;
    return 0;
}