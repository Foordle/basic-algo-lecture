#include <iostream>

using namespace std;

int main(void) {
    int n;
    int arr[50];
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cout << arr[i] - arr[i+1] << endl;
    }
    return 0;
}