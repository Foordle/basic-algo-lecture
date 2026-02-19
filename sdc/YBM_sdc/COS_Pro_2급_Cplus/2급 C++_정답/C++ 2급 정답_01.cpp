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
            if (arr[j] < arr[min_idx])
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