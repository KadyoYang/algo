#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        int maxSizeOfVector = strs.size();

        int minLength = strs[0].size();
        for(std::vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++){
            minLength = ((*iter).length() < minLength) ? (*iter).length() : minLength;
        }
        if(minLength == 0){
            return "";
        }

        // int result = 0;
        bool result = true;
        char ch;
        int i = 0;
        for(i = 0; i < minLength; i++){
            ch = (strs[0]).at(i);
            for(int j = 1; j < maxSizeOfVector; j++){
                if(ch != (strs[j]).at(i)){
                    result = false;
                    break;
                }
            }

            if(!result){
                break;
            }
        }
        return (strs[0]).substr(0, i);

    }
};

int main(){
    Solution sol;
    vector<string> tc1 = {"flower", "flow", "flight"};
    cout << tc1.at(0) << endl;
    cout << sol.longestCommonPrefix(tc1) << endl;
    return 0;
}