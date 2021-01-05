// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [], target = 0
// Output: []
 

// Constraints:

// 0 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int numsSize = nums.size();

        vector<vector<int>> result;

        int val = 0;
        int head = 0;
        int rear = 0;
        for(int i = 0; i < numsSize - 3; i++){
            if(i > 0 && (nums[i] == nums[i-1])) continue; 
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;

            for(int j = i+1; j < numsSize - 2; j++){
                if(j > i+1 && (nums[j] == nums[j-1])) continue; 
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                head = j+1;
                rear = numsSize - 1;
                while(head < rear){
                    val = nums[i] + nums[j] + nums[head] + nums[rear];
                    if(val > target) rear--;
                    else if(val < target) head++;
                    else{
                         vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[head];
                        quad[3] = nums[rear];
                        result.push_back(quad); 

                        while(head < rear && quad[2] == nums[head]) head++;
                        while(head < rear && quad[3] == nums[rear]) rear--;
                        
                       /*
                        result.push_back(vector<int>{nums[i], nums[j], nums[head], nums[rear]});
                        while(head < rear && nums[head] == nums[head-1]) head++;
                        while(head < rear && nums[rear] == nums[rear+1])
                        */
                    }

                }
                // while(j < numsSize && nums[j] == nums[j+1]) j++;
                
            }
            // while(i+1 < numsSize && nums[i] == nums[i+1]) i++;
        }

        return result;
    }
};


int main(){
    Solution sol;

    vector<int> tc1 = {-3,-2,-1,0,0,1,2,3};

    vector<vector<int>> result = sol.fourSum(tc1, 0);
    
    for(const vector<int>& el: result){
        for(const int &val: el){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}