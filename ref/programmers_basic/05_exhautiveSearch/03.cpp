#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<int> solution(int brown, int yellow){
    int yellowY = 1;
    int yellowX = yellow / yellowY;

    while(yellowX >= yellowY){
        if(brown == ((yellowX+1) + (yellowY+1)) * 2){
            break;
        }else{
            do{
                yellowY++;
                yellowX = yellow / yellowY;
            }while(yellow % yellowY != 0);
        }
    }

    return vector<int>{yellowX+2, yellowY+2};
}