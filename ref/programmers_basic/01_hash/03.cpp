#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> temp;

    for(auto cloth : clothes){
        if(temp.find(cloth[1]) == temp.end()){
            temp.insert(make_pair(cloth[1], 1));
        }else{
            temp[cloth[1]] += 1;
        }
    }

    for(auto iter = temp.begin(); iter != temp.end(); iter++){
        answer *= ((*iter).second+1);
    }
    
    return answer-1;
}


int main(){
    vector<vector<string>> tc1 = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(tc1) << endl;


    return 0;
}