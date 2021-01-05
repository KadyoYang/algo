#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 먼저 0번째가 타겟보다 큰지 작은지 
        // 뒤 나 앞  타겟보다 크면 뒤 작으면 앞
        if(nums.size() == 1 && nums[0] == target) return 0;
        if(nums.size() == 1 && nums[0] != target) return -1;
        int pivot = findPivotIndex(nums);

        if(nums[0] < target){
            // 0 부터 pivot -1 까지 써치
            return findNum(nums, target, 0, pivot-1);

        }else if(nums[0] > target){
            // pivot 부터 nums.size() -1 까지 써치
            return findNum(nums, target, pivot,  nums.size() - 1);
        }else{
            return 0;
        }
        
        
    }
    
    int findPivotIndex(vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;

        cout << "hel" << endl;
/*         while(!(nums[((left+right)/2) - 1] > nums[nums.size()-1] &&  nums[((left+right)/2) - 1] > nums[((left+right)/2)] )){
            if(nums[((left+right)/2)] > nums[nums.size()-1]) left = ((left+right)/2);
            else right = ((left+right)/2);
        } */
        while(left <= right){
            if ((nums[((left+right)/2)] > nums[nums.size()-1] && nums[((left+right)/2)] > nums[((left+right)/2)+1])) return ((left+right)/2)+1;
            else if(nums[((left+right)/2)] > nums[nums.size()-1] ) left = ((left+right)/2)+1;
            // else if(nums[((left+right)/2)] > nums[nums.size()-1] && nums[((left+right)/2)] < nums[((left+right)/2)+1]) left = ((left+right)/2)+1;
            // else if(nums[((left+right)/2)] < nums[nums.size()-1]) right = ((left+right)/2); 
            else right = ((left+right)/2)-1;
        }
        return 0;
    }

    int findNum(vector<int>& nums, int& target, int left, int right){
        if(nums[right] < target) return -1;
        while(left <= right){
            if(nums[(left+right)/2] < target) left = ((left+right)/2)+1;
            else if(nums[(left+right)/2] > target) right = ((left+right)/2)-1;
            else return (left+right)/2;
        }
        return -1;
    }
};


int main(){
    Solution sol;

/*      vector<int> testArray1 = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> testArray2 = {8, 9, 0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> testArray3 = {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
    vector<int> testArray4 = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    vector<int> testArray5 = {1, 2, 0};
    vector<int> testArray6 = {2,0,1};
    vector<int> testArray7 = {1,0};


    vector<int> testArray8 = {8, 9, 1, 2, 3, 4, 5, 6, 7};
    vector<int> testArray9 = {3, 4, 5, 6, 7, 8, 9, 1, 2};
    
    
     cout << sol.findPivotIndex(testArray1) << endl;
    cout << sol.findPivotIndex(testArray2) << endl;
    cout << sol.findPivotIndex(testArray3) << endl;
    cout << sol.findPivotIndex(testArray4) << endl;
    cout << sol.findPivotIndex(testArray5) << endl;
    cout << sol.findPivotIndex(testArray6) << endl;
    cout << sol.findPivotIndex(testArray7) << endl;
    cout << sol.findPivotIndex(testArray8) << endl;
    cout << sol.findPivotIndex(testArray9) << endl; */

    vector<int> z1 = {0,1};
    vector<int> z2 = {0,1,2};
    vector<int> z3 = {0,1,2, 3};

    cout << sol.findPivotIndex(z1) << endl;
    cout << sol.findPivotIndex(z2) << endl;
    cout << sol.findPivotIndex(z3) << endl;

    // vector<int> test = {4,5,6,7,0,1,2};
    // cout << sol.findPivotIndex(test) << endl; 
    //cout << sol.search(test, 3);

/*     vector<int> test = {1};
    sol.search(test, 0); */
    return 0;
}