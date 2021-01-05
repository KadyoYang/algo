#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        
        int ans = 0;
        for(int i = 0; i < A[0].length(); ++i){
            for(int j = 0; j < A.size()-1; ++j){
                if(A[j].at(i) > A[j+1].at(i)){
                    ans++;
                    break;
                }
            }
        }


    }
};