#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;



class Solution {
private:
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target, temp);

        return result;
    }


    void backtrack(vector<int>& candidates, int n, int target, vector<int>& temp ){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if( target < 0) return;
        
        for(int i = n; i < candidates.size(); i++){
            if(i && candidates[i]==candidates[i-1] && i>n) continue; // sorting 되있다는 가정하에
            // n번째 들어간 이후 n+1(i) 되어가면서 뒤엣거랑 똑같은 놈이면 넘어가랏
            // 그 재귀는 이미 전번째에 한 재귀일테니

            temp.push_back(candidates[i]);
            backtrack(candidates, i+1, target-candidates[i], temp);
            temp.pop_back();
        }


    }

};




int main(){

/*
[10,1,2,7,6,1,5]
8

*/

    Solution sol;
    vector<int> tc1 = {10,1,2,7,6,1,5};

    sol.combinationSum2(tc1, 8);
}