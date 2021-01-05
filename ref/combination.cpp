#include <iostream>
#include <vector>
#include <string>
#include <deque>


using namespace std;

int combination(int n, int r){

    if(n == r || r == 0){
        return 1;
    }else{
        return combination(n-1, r-1) + combination(n-1, r);
    }
}

/**
 * 2020 09 24 yang kydo
 * src는 조합을 구하고싶은 원본문자열
 * r은 갯수 
 * target은 만들어지고있는것 "" 초기값으로 주세요
 * &des는 결과물 저장용 
*/
int combinationStr(string src, int r, string target, vector<string> &des){
    // cout << target << " DEA"<< endl;
    if(target.size() == r){
        des.push_back(target);
        return 0;
    }else if(src.size() == 0){
        return 1;
    }else{
        // 첫번째거(원했던거) 포함됨
        combinationStr(src.substr(1, src.size()-1), r, target + src[0], des);
        // 첫번째거 포함안됨
        combinationStr(src.substr(1, src.size()-1), r, target, des);
    
        return 0;
    }
}



int main(){
    // cout << composite(6, 2) << endl;
    
    vector<string> des;

    combinationStr("abcd", 4, "", des);

    for(int i =0 ; i < des.size(); i++){
        cout << des[i] << endl;
    }
}