#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // using binary search
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;

        while(left < right){
            mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        cout <<"left : " << left << " right : " << right << endl;

        if(left == right){
            if(nums[left] >= target) return left;
            else left+1;
        }else{
            return left;
        }
        return 0;
    }
    
};


int main(){
    Solution sol;

    vector<int> tc1 = {0,1,2,3,4,5,6,7,8};
    vector<int> tc2 = {0,1,2,3,4,5,6,8,9};
    vector<int> tc3 = {0,1,2,3,4};
    vector<int> tc4 = {0,1,2,3,4};

    cout << sol.searchInsert(tc1, 3) <<endl;
    cout << sol.searchInsert(tc2, 7)<<endl;
    cout << sol.searchInsert(tc3, 0)<<endl;
    cout << sol.searchInsert(tc4, 6)<<endl;
    return 0;
}