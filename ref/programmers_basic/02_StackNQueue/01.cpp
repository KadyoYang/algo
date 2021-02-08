#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for(int i = 0; i < prices.size()-1; ++i){
        int second = 0;
        
        for(int j = i+1; j < prices.size(); ++j){
            second++;
            if(prices[j] < prices[i]) break;
        }
        answer[i]= second;
    }
    return answer;
}



int main(){
    vector<int> tc = {1,2,3,2,3};

    
    solution(tc);
    return 0;
}