#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int originalSize = nums.size();
        if(originalSize < 2) return originalSize;
        int fixedIdx = 0;
        int target = 1;
        for(int i = 1; i < originalSize; i++){
            if(nums[fixedIdx] == nums[i]) continue;
            else{
                nums[target] = nums[i];
                target++;
                fixedIdx++;
            }
        }
        for(++fixedIdx; fixedIdx < originalSize; fixedIdx++){
            nums.pop_back();
        }
        return target;
    }
};