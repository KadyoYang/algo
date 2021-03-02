
#include <iostream>
#include <string>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";

    int start = -1;
    
    for(int i = 0; i < number.length()-k;i++){
        char max = 0;
        for(int j = start+1; j <= k+i ; j++){
            if(max < number[j]){
                start = j;
                max = number[j];
            }
        }
        answer += max;
    }


    /* for(int i = 0, start = -1; i < number.length() - k; i++){
        char max = 0;
        for(int j = start + 1; j <= k + i; j++){
            if(max < number[j]){
                start = j;
                max = number[j];
            }
        }
        answer += max;
    } */







    return answer;
 
}