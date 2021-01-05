#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int head = i+1;
        int rear = n-1;
        int result = nums[0] + nums[head] + nums[rear];

        int temp = 0;

        for(i = 0; i < n-2; i++){
            head = i+1;
            rear = n-1;
            while(head < rear){
                temp = nums[i] + nums[head] + nums[rear];
                if(abs(temp - target) < abs(result - target)){
                    result = temp;
                }
                if(temp > target){
                    rear--;
                }else{
                    head++;
                }
            }

        }

        return result;
    }
/* 
private:
    int calcDistance(int src, int des){
        if(src > des){
            return (src-des);
        }else{
            return (des-src);
        }
    } */
};

int main(){

    return 0;
}
