#include <iostream>
#include <vector>
using namespace std;

string solution(int money, vector<vector<int>> cost, vector<string> name) {
    string answer ="";
    long max_distance = 0;

    for (int i = 0; i < cost.size(); i++) {
        int oil = money / cost[i][1];
        long distance = cost[i][0] * oil;
        if (distance > max_distance) {
            max_distance = distance;
            answer = name[i];
        }
    }

    return answer;
}

int main() {
    int money = 100000;
    vector<vector<int>> cost = { {50, 5000}, {20, 1000}, {20, 5000}, {50, 1000} };
    vector<string> name = { "A", "B", "C", "D" };

    string ret = solution(money, cost, name);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
    return 0;
}