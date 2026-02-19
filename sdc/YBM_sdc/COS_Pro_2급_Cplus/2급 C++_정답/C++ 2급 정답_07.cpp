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
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}