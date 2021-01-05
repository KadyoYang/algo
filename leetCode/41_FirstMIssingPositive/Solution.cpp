#include <iosteram>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for(int i = 0; i < size; ++i){
            while(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] -1 ]);
        }

        for(int i = 0; i < size; ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return size+1;
    }
};

class Solution1
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};