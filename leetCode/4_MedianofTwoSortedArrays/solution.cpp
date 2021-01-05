#include <iostream>
#include <vector>


using namespace std;

/*
Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int m = nums1.size(), n = nums2.size();
        int mn = m+n;
        int x = (int)(mn/2) - 1;
        int temp;

        cout << "x = " << x << endl;

        int i = 0;
        vector<int>::iterator iter1 = nums1.begin(); 
        vector<int>::iterator iter2 = nums2.begin();
        while(i <= x+1){
            if(iter1 == nums1.end()){
                // iter1이 동났다!
                // iter2 다 들이부어
                while(i <= x+1){
                    result.push_back(*(iter2++));
                    i++;
                }
                break;
            }
            if(iter2 == nums2.end()){
                // iter2가 동났다!
                // iter1 다 들이부어
                 while(i <= x+1){
                    result.push_back(*(iter1++));
                    i++;
                }
                break;
            }
            // 둘다 안동났다
            temp = ((*iter1) <= (*iter2))?*(iter1++):*(iter2++);
            result.push_back(temp);
            i++;
        }
        if(mn%2 == 0){
            //목표는 두개가된다
            return (result.at(x) + result.at(x+1)) / 2.0;
        }else{
            // 목표는 하나
            return result.at(x+1);    
        } 
    }
};

class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(n == 0){
            if(m&1)
                return nums2[m/2];
            else
                return (double) (nums2[m/2]+nums2[m/2-1])/2;
        }
        
        int low = 0, high = n;
        int partitionx, partitiony;
        int xMax, xMin, yMax, yMin;
        
        while(low <= high) {
            partitionx = (low+high)/2;
            partitiony = (n+m+1)/2 - partitionx;
            
            xMin = partitionx == 0 ? INT8_MIN : nums1[partitionx-1];
            xMax = partitionx == n ? INT8_MAX : nums1[partitionx];
            
            yMin = partitiony == 0 ? INT8_MIN : nums2[partitiony-1];
            yMax = partitiony == m ? INT8_MAX : nums2[partitiony];
            
            if(xMin <= yMax && yMin <= xMax) {
                if((n+m)%2 == 0) 
                   return double(max(xMin,yMin) +min(xMax, yMax))/2.0; 
                else
                    return double(max(xMin,yMin));
            }
            else if(xMin <= yMax) 
                low = partitionx+1;
            else 
                high = partitionx-1;
        }
        return 1.0;
    }
};


int main(){
    cout << "hello test" << endl;
    vector<int> a {3};
    vector<int> b {1,4,5,9,11,15,28,188,200,201,202};
    Solution1 sol;
    cout << sol.findMedianSortedArrays(a,b);
    return 0;
}