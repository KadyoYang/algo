#include <string>
#include <vector>
#include <queue>
#include <iostream>



using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> a; 
    priority_queue<int, vector<int>, greater<int>> b;
    
    int totalSize = 0;
    for(string ops : operations){
        if(ops.compare("D 1") == 0){
            if(a.size() + b.size() > totalSize){
                a.pop();
            }
                
        }else if(ops.compare("D -1") == 0){
            if(a.size() + b.size() > totalSize){
                b.pop();
            }
                
        }else{
            int val = atoi(ops.substr(2, ops.size()).c_str());
            a.push(val);
            b.push(val);
            ++totalSize;
        }

    }
    cout << a.size() << endl;
    cout << b.size() << endl;
    cout << totalSize << endl;

    if(a.size() + b.size() > totalSize){
        answer.push_back(a.top());
        answer.push_back(b.top());
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}




int main(){

    // priority_queue<int> a;

    // a.push(1);a.push(4);a.push(-1);a.push(-4);

    // cout << a.top() << endl;
    // a.pop();
    // cout << a.top() << endl;

    // string test = "I -12345";
    
    // cout << 1 + atoi(test.substr(2, test.size()).c_str()) << endl;
    
    // priority_queue<int, deque<int>, less<int>> a;

    vector<string> a = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    
    cout << solution(a).at(0) << endl;

    
    // a.push_back(1);
    // a.push_back(2);
    // a.push_back(3);
    // a.push_back(2);
    // a.push_back(6);

    // cout << a.front() << endl;
    // a.pop_front();
    // cout << a.front() << endl;
    // a.pop_front();
    // cout << a.front() << endl;
    // a.pop_front();
    //     cout << a.front() << endl;
    // a.pop_front();
    //     cout << a.front() << endl;
    // a.pop_front();
    //     cout << a.front() << endl;
    // a.pop_front();

    return 0;
}