#include <iostream>
using namespace std;





int main(){
    int a = 4;
    int* ap = &a;
    int** app = &ap;

    cout << a << endl;
    cout << &a << endl;

    cout << endl;

    cout << *ap << endl;
    cout << ap << endl;
    cout << &ap << endl;

    cout << endl;

    cout << **app << endl;
    cout << *app << endl;
    cout << app << endl;
    

    return 0;
}