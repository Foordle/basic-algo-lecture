#include <iostream>

using namespace std;

int main(void) {
    int num1;
    int num2;
    cin >> num1 >> num2;
    if(num1 == num2)
        printf("%d\n", num1 + num2);
    else
        printf("%d\n", num2 - num1);
    return 0;
}