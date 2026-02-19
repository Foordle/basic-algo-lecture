#include <iostream>

using namespace std;

int main(void) {
    string s;
    int answer = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '1')
            answer++;
    printf("%d\n", answer);
    return 0;
}