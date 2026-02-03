
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int arr[100][100] = {0};
int a;

void rotate(int y, int x, int size, int rt) {
    for (int i = 0; i < rt; i++) {
        int arr2[100][100] = {0}; //회전을 반영하여 옮기기 위한 빈 배열
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                arr2[y + k][x + j] = arr[y + j][x + size - 1 - k];
            }
        }

        for (int i = 0; i < a; i++) // 원본에 1회전 결과 반영
        {
            for (int j = 0; j < a; j++) {
                if (arr2[i][j] != 0) {
                    arr[i][j] = arr2[i][j];
                }
            }
        }

        int main()
        {
            cin >> a;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < a; j++) {
                    cin >> arr[i][j];
                }
            }
            int b;
            cin >> b;
            int arr1[100][4] = {0};
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < 4; j++) {
                    cin >> arr1[i][j];
                }
            }

            for (int i = 0; i < b; i++) {
                rotate(arr1[i][0], arr1[i][1], arr1[i][2], arr1[i][3]);
            }
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < a; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << '\n';
            }
        }
