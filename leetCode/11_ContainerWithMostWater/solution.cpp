#include <iostream>
#include <vector>

using namespace std;
class Solution{
    public:
    int maxArea(vector<int>& height){
        int result = 0;
        
        int front = 0;
        int rear = height.size() - 1;

        while(front < rear){
            if(height[front] <= height[rear]){
                // 뒤가 더 크다.. 뒤는 냅두고 작을걸로 계산하고 작은거 앞으로 전진!
                result = ((rear - front) * height[front])>result?((rear - front) * height[front]):result;
                front++;
            }else{
                // 앞이 더 크다
                result = (((rear - front) * height[rear])>result) ? ((rear - front) * height[rear]):result;
                rear--;
            }
        }
        return result;
    }
};


int main(){
    Solution sol;
    vector<int> tc1 = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(tc1) << endl;
}