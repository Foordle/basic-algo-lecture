#include <iostream>

using namespace std;

int main(void) {
    string num1;
    string num2;
    cin >> num1 >> num2;
    
    if(num1.size() > num2.size())
        cout << num1;
    else
        cout << num2;
    return 0;
}