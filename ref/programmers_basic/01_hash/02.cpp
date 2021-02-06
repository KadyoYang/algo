#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;
/** 어차피 똑같은 번호는 없다 */
bool solution(vector<string> phone_book) {
    unordered_set<int> lengths;
    unordered_set<string> temp;

    for(auto str : phone_book){
        if(lengths.find(str.length()) == lengths.end()) lengths.insert(str.length());
    }

    for(auto str: phone_book){
        for(auto i : lengths){
            if(str.length() <= i) continue;
            if(temp.find(str.substr(0, i)) == temp.end()){
                // cout << str.substr(0, i) << endl;
                temp.insert(str.substr(0, i));
            }
        }
    }

    for(auto str: phone_book){
        if(temp.find(str) != temp.end()) return false;
    }

    return true;
}


int main(){
    vector<string> tc = {"00000000", "9999", "111", "22222", "555555"};
    cout << solution(tc) << endl;

    return 0;
}