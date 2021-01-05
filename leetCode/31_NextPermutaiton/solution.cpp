#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 다음크기로 조합하라 만약 큰게 없다면 
// 맨 처음 오름차순으로 해라
class Solution {
public:

    void nextPermutation(vector<int>& nums) {
	    const int n = nums.size();
	    int i,j;
	    for(i=n-1; i>=1 && nums[i-1]>=nums[i];--i);
	    if(i>0){
		    for(j=i; j<=n-1 && nums[j]>nums[i-1];++j);
		        swap(nums[i-1], nums[j-1]);
	    }
	    reverse(nums.begin()+i,nums.end()); 
    }
};

