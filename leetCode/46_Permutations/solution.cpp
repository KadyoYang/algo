#include <iostream>
#include <vector>



// given an array nums of distinct integers, 
// return all the possible permutations.
// you can return the answer in any order

// input 0 1 
// output 1 0, 0 1


using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> result;
        recur(nums,0 ,result);
        return result;
    }


    void recur(vector<int> &nums, int start, vector<vector<int>> &result){
        if(start >= nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){

            swap(nums[start], nums[i]);
            recur(nums, start+1, result);
            swap(nums[start], nums[i]);
        }
    }
};

/* 
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    // reset
		    swap(num[begin], num[i]);
		}
    }
}; */
