#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> temp;

    for(string str: completion){
        if(temp.find(str) == temp.end()){
            temp.insert(make_pair(str, 1));
        }else{
            temp[str]++;
        }  
    }
       
    for(string str: participant){
        if(temp.find(str) == temp.end()){
            return str;
        }else{
            temp[str]--;
            if(temp[str] < 0) return str;
        }
    }
    return "";
}


string solution1(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
}


int main(){
    vector<string> part = {"a", "b", "c"};
    vector<string> comp = {"a", "c"};

    
}


