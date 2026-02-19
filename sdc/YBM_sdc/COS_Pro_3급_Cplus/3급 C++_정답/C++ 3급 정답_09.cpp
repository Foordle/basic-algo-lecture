#include <iostream>

using namespace std;

int main(void) {
    string n;
    cin >> n;
    for(int i = n.size()-1; i > -1; i--) {
        cout << n[i];
    }
    return 0;
}