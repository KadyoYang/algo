#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<int> temp;
        backtrack(candidates, target, 0, temp);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int index, vector<int>& temp){
        if(!target){
            result.push_back(temp);
            cout << "칼!" <<endl;
            for(int i : temp) cout << i << " ";
            cout << endl;
        }
        if(target < 0) return;

        for(int i = index; i < candidates.size(); ++i){
            temp.push_back(candidates[i]);
            cout << candidates[i] << endl;
            backtrack(candidates, target - candidates[i], i, temp);
            cout << "뒤로" <<endl;
            temp.pop_back();
        }
    }
};

int main(){

    Solution sol;
    vector<int> testcase1 = {2,3,6,7};
    sol.combinationSum(testcase1, 7);
    return 0;
}




// Accepted 16ms c++ solution use backtracking for Combination Sum:
class Solution1 {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};






// Accepted 12ms c++ solution use backtracking for Combination Sum II:

class Solution2 {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};




// Accepted 0ms c++ solution use backtracking for Combination Sum III:

class Solution3 {
public:
    std::vector<std::vector<int> > combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum3(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationSum3(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        else if (!need)
            return;
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(target - i, res, combination, i + 1, need - 1);
            combination.pop_back();
        }
    }
};