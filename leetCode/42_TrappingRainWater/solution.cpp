#include <vector>
#include <iostream>
#include <stdlib.h>


using namespace std;


class Solution {
public:
    // dynamic
    int trap(vector<int>& height){
        int result = 0;
        if(height.empty()) return result;
        int size = height.size();
        vector<int> leftMax(size);
        vector<int> rightMax(size);
    

        leftMax[0] = height[0];
        for(int i = 1; i < size; i++){
            leftMax[i] = (leftMax[i-1] < height[i])? height[i] : leftMax[i-1];
        }

        rightMax[size-1] = height[size-1];
        for(int i = size-2; i > -1; i--){
            rightMax[i] = (rightMax[i+1] < height[i])? height[i] : rightMax[i+1];
            cout << rightMax[i] << " " ;
        }

        // min 구해가면서 물 양 구하자
        for(int i = 1; i < size-1; i++){
            result += min(leftMax[i], rightMax[i])-height[i];
        }
    return result;
    }

// two pointer
    int trap2(vector<int>& height)
    {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}

};



int main(){
    Solution sol;
    vector<int> tc1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> tc2 = {4,2,0,3,2,5};
    cout <<endl<< sol.trap(tc1) << endl;
    // cout << (sol.trap(tc1) == tc1a) << endl;
    cout << endl<<sol.trap(tc2) << endl;
    // cout << (sol.trap(tc2) == tc2a) << endl;
    return 0;
}