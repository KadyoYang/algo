#include <iostream>
#include <vector>
#include <string>

using namespace std;
string deleteOneLetter(string src, int index);
/**
 * src은 순열을 구하고싶은 문자열
 * r은 갯수
 * target은 ""을 초기값으로 주세요
 * &des는 결과저장용
 *
 * */
int permutationStr(string src, int r, string target, vector<string> &des){
    
    if(target.size() == r){
        des.push_back(target);
        return 0;
    }else if(src.size() == 0){
        return 1;
    }else{
        for(int i = 0; i < src.size(); i++){
            // 쫘아아아악
            permutationStr(deleteOneLetter(src, i), r, target + src[i], des);
        }
    }
    return 0;
}
/**
 * &src 원본문자열
 * index 없애고싶은 인덱스문자
 * 리턴은 없앤문자뺀 문자열
 * */
string deleteOneLetter(string src, int index){
    if (src.size() == 0){
        return "";
    }
    if(index == 0){
        return src.substr(1, src.size()-1);
    }
    return (src.substr(0, index) + src.substr(index+1, src.size() - index+1));
}


int main(){
    vector<string> result;

   /*  string src = "abcd";
    for(int i = 0; i < src.size(); i ++){
        cout << deleteOneLetter(src, i) << " deleted" <<endl;
    } */
    

    permutationStr("abcdef", 4, "", result);

    for(int i =0 ; i < result.size(); i++){
        cout << result[i] << endl;
    }
    cout << "total number = " << result.size() << endl;
    return 0;
}