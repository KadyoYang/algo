#include <iostream>
#include <vector>
#include <exception>
#include <map>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if((nums.at(i) + nums.at(j)) == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> answer;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int needed_num = target - nums[i];
            
            if (cache.find(needed_num) != cache.end())
            {
                // We found it
                answer.push_back(cache[needed_num]);
                answer.push_back(i);
                return answer;
            }
            else
            {
                // Didn't find it
                cout<<"didnt find it"<<endl;
                
                cache.insert(make_pair(nums[i], i));
            }
        }
        return answer;
    }
};

void printVectorEle(vector<int> ele){
    for(vector<int>::iterator iter = ele.begin(); iter != ele.end(); iter++){
        cout<< *iter << " ";
    }
    cout<< endl;
}

int main(){
    vector<int> testCase1 = {2,7,11,15};
    vector<int> testCase2 = {3,2,4};
    vector<int> testCase3 = {3,3};

    Solution1 sol;

    printVectorEle(sol.twoSum(testCase1, 9));
    printVectorEle(sol.twoSum(testCase2, 6));
    printVectorEle(sol.twoSum(testCase3, 6));
    return 0;
}