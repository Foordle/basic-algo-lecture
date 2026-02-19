#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

int solution(vector<vector<int>> arr, int N)
{
	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int a = arr[i][0];
		int b = arr[i][1];

		int c = gcd(a, b);

		if (c > answer)
		{
			answer = c;
		}
	}

	return answer;
}

int gcd(int a, int b)
{
	if ([[quiz]])
	{
		return [[quiz]];
	}
	else
	{
		return [[quiz]];
	}
}

int main() {    
    
	vector<vector<int>> arr1 = {{15,20},{36,48},{12,7},{121,44},{39,65}};
	int N1 = 5;
	int ret1 = solution(arr1, N1);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	vector<vector<int>> arr2 = {{356,78},{154,122},{38,190},{44,188},{365,245}};
	int N2 = 5;
	int ret2 = solution(arr2, N2);
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;

}
