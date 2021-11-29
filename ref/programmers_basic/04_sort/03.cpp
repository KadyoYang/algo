#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
1 2 3 4 8 8 8 8 8 8 일때 
h index 는 6이어야하지 

*/


int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());
    int i = 0;
    for(i = 0; i < citations.size(); ++i){
        if(citations[i] <= citations.size() - i){
            answer = citations[i];
        }else{
            break;
        }
    }

    while(i < citations.size()){
        if((answer+1) <= citations[i] && (answer+1) <= citations.size()-i){
            answer++;
        }else{
            break;
        }
        

    }
    return answer;
}


// better solution 

int solution_1(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}


int main(){

    vector<int> a{3, 0, 6, 1, 5};
    
    cout << solution_1(a) << endl;

    return 0;
}