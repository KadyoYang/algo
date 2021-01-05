#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/* 
이거는 입력값이 많을때 수행시간 큰일난다.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> tar;
        getThreeSum(nums, tar, result);
        return result;
    }
private:
    void getThreeSum(vector<int> nums, vector<int> tar, vector<vector<int>> &result){
        cout << nums.size() << " " << tar.size() << endl;
        if(tar.size() == 3 && sumVectorInt(tar) == 0){
            std::sort(tar.begin(), tar.end());
            if(dupleCheck(tar, result)){return;}
            result.push_back(tar);
            return;
        }else if(nums.empty()){
            return;
        }else{
            // nCr = n-1Cr-1 + n-1Cr
            int myNumber = nums.back();
            nums.pop_back();

            getThreeSum(nums, tar, result);

            tar.push_back(myNumber);
            getThreeSum(nums, tar, result);
        }
        return;
    }


    int sumVectorInt(vector<int> &tar){
        if(tar.empty()){
            return 1;
        }
        int sum = 0;
        for(int i = 0; i < tar.size(); i++){
            sum += tar[i];
        }
        return sum;
    }
    **
     * 중복이면 true 반환
    *
    bool dupleCheck(vector<int> tar, vector<vector<int>> &result){
        bool res = false;
        for(int i = 0; i < result.size(); i++){
            if(result[i] == tar){
                res = true;
                break;
            }
        }
        return res;
    }
}; 
*/

class Solution{
public:

vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
// 기준점잡아놓고 투폰이터 돌려서 0되는거 찾고 넣고 그다음꺼 찾아야할때 투포인터 이거 암튼
// 처음에 nums 정렬해놨자나 그래서 그거 자기꺼 중복이 끝나는 index까지 이동한다음부터 다시 서치시작
vector<vector<int>> threeSum2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        // 기준점 잡아놓고
        for(int i=0;i<n-2;i++){
            // 기준점 중복되는거였으면 그 중복의 마지막인덱스 사용 
               if(i>0 && (nums[i]==nums[i-1]) )continue;
               int l=i+1, r= n-1;

               // 서치시작
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   
                   if(sum<0) l++;
                   else if(sum>0)r--;
                   else {
                       res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                       while(l+1<r && nums[l]==nums[l+1])l++;
                       while(l<r-1 && nums[r]==nums[r-1]) r--;
                       l++; r--;
                   }
               }
        }
       
        return res;
    }
};

int main(){
    vector<int> tc1 = {-1,0,1,2,-1,4};
    Solution sol;
    vector<vector<int>> result;
    result = sol.threeSum(tc1);

    
    for(vector<vector<int>>::iterator iter1 = result.begin(); iter1 != result.end(); iter1++){
        for(vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}