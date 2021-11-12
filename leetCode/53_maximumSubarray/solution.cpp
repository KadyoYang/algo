#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums, 
find the contiguous subarray (containing at least one number) which has the largest sum and
return its sum
A subarray is a contiguous part of an array 

O(n) 솔루션 찾아라 

ex)
nums = [-2,1,-3,4,-1,2,1,-5,4]
6
[4,-1,2,1] has the largest sum = 6.
*/

class Solution{
    public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;

        for(int i = 0; i < nums.size(); ++i){
            currentSum = currentSum + nums[i];

        }
    }
};