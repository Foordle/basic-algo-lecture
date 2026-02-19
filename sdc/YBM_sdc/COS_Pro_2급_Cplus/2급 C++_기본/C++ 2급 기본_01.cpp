#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int N, int M)
{
    int answer = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] > arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }

    for (int i = 1; i < N; i++)
    {
        if (i % M == 0)
        {
            answer += arr[i];
        }
    }

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니 위의 코드만 수정하세요.

int main() {    
    
	vector<int> arr1 = {4,2,1,3,9,5,6};
	int N1 = 7;
	int M1 = 3;
	int ret1 = solution(arr1, N1, M1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<int> arr2 = {7,6,5,4,3,2,1};
	int N2 = 7;
	int M2 = 3;
	int ret2 = solution(arr2, N2, M2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

	vector<int> arr3 = {8,6,3,3,4,1,5,7};
	int N3 = 8;
	int M3 = 2;
	int ret3 = solution(arr3, N3, M3);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret3 << " 입니다." << endl;

}
