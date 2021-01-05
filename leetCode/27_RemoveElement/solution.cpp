#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int targetIdx = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (nums[i] != val) {
                nums[targetIdx] = nums[i];
                targetIdx++;
            }
        }
        return targetIdx;
    }
};




// 0 1 2 2 3 0 4 2     2
// 0 1 3 0 4


int main(){

    vector<int> tc1 = {0,1,2,3,2,3,2,3,0,4,2};
    Solution sol;
    sol.removeElement(tc1, 2);
    return 0;
}
