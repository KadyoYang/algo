#include <iostream>
#include <string>
#include <vector>

/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

숫자는 0에서 10의5승
*/
using namespace std;
class Solution{
public:
    int jump(vector<int>& nums){
        int result = 0;
        int currentPosition = 0;
        while(currentPosition != nums.size()-1){
            currentPosition = calBestChoice(nums, currentPosition);
            result++;
        }
        
        return result;
    }

    
    int calBestChoice(vector<int>& nums, int& currentPosition){
        int maxIndex = nums[currentPosition] + currentPosition;

        // 현재 위치에서 끝까지 갈 수 있다
        if(maxIndex >= nums.size()-1) return nums.size()-1;

        // 가중치 더해서 최선의 위치 계산
        int bestChoice = currentPosition+1;
        
        for(int i = currentPosition+2;
            i <= maxIndex;
            i++){

                if(nums[i]+i > nums[bestChoice]+bestChoice) bestChoice = i;
        }

        return bestChoice;
    }
};