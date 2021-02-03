#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        recur(nums, 0, result);
        return result;
    }

    void recur(vector<int> nums, int start, vector<vector<int>> &result){
        if (start >= nums.size()){
            result.push_back(nums);
            return;
        }else{
            for (int i = start; i < nums.size(); i++){
                if (i== start || nums[i] != nums[start]){
                    swap(nums[start], nums[i]);
                    recur(nums, start + 1, result);
                }

            }
        }
    }
};