#include <iostream>
#include <vector>


using namespace std;




class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if(nums.empty()) return result;
        binarySearch(nums, target, result);

        return result;
        

    }

    /* int binarySearch(vector<int>& nums, int& target){
        int left = 0, right = nums.size()-1, mid = 0;


        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    } */

        void binarySearch(vector<int>& nums, int& target, vector<int>& result){
        int left = 0, right = nums.size()-1, mid = 0;

        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target && (mid==0 || ( mid-1 > -1 && nums[mid-1] != target))) {result[0] = mid; break;}
            else if(nums[mid] >= target) right = mid-1;
            else left = mid+1;
        }
        if (result[0] == -1) return;
        
        left = result[0];
        right = nums.size() - 1;
        mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target && (mid==nums.size()-1 || ( mid+1 < nums.size() && nums[mid+1] != target))) {result[1] = mid; break;}
            else if(nums[mid] <= target) left = mid+1;
            else right = mid-1;
        }

        return;
    }

};