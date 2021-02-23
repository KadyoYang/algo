#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int makeThousand(int x){
    if(x == 0) return 0;

    int unit = 0;
    int diver = 0;
    while(x/(int)pow(10, unit) != 0) {
        unit++;
    }

    diver = (int)pow(10, --unit);
    
    while(x/1000 == 0){
        int temp = (x / diver) % 10;
        x = (x*10) + temp;
    }
    return x;
}

bool compare(int &a, int &b){
    return makeThousand(a) > makeThousand(b);
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);
    for(int number: numbers){
        answer.append(to_string(number));
    }
    return answer;
}


int main(){
    cout << makeThousand(0) << endl;
    cout << makeThousand(1) << endl;
    cout << makeThousand(12) << endl;
    cout << makeThousand(123) << endl;
    cout << makeThousand(5621) << endl;
    cout << makeThousand(1000) << endl;
    cout << makeThousand(606) << endl;
    cout << makeThousand(10) << endl;
    cout << makeThousand(100) << endl;
    cout << makeThousand(110) << endl;
    cout << makeThousand(111) << endl;


    return 0;
}
