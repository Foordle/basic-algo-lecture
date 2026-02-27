#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_NUMBER_OF_CANDIDATE 2
#define CMD_MAX_AREA 3

extern void init(int N, int mMap[20][20]);
extern int numberOfCandidate(int M, int mStructure[5]);
extern int maxArea(int M, int mStructure[5], int mSeaLevel);
/* 시간 복잡도 계산
 * 하나의 test case당 12,000,000 가능
 * M [1, 5]
 * mStruct [1, 5]
 * mSealevel [1, 10]
 * N [5, 20]
 * mMap [1, 5]
 */
/////////////////////////////////////////////////////////////////////////
const int maxNodeNum = 2000; // 20x20 맵에서 가로/세로 케이스를 담기에 충분한 크기
const int MAX_HASH = 10000;  // 차이값(0~4) 4자리를 숫자로 변환 (최대 4444)

struct Pos {
    int nxt;
    int row;
    int col;
};

Pos Pool[maxNodeNum];
int poolIdx = 0;
int freeIdxPool[maxNodeNum];
int freeIdx = 0; // 0번을 비우기 위해 1부터 사용하거나 push 전 증가

// DAT 배열: 각 해시 키(지형 차이 조합)별 연결 리스트의 시작점(head) 저장
int rowDAT[MAX_HASH];
int colDAT[MAX_HASH];

// 노드 할당
int alloc(int y, int x) {
    int nodeN;
    if (freeIdx > 0) {
        nodeN = freeIdxPool[freeIdx--]; // 0번을 비우기 위해 사용 후 감소
    } else {
        nodeN = poolIdx++;
    }
    Pool[nodeN].row = y;
    Pool[nodeN].col = x;
    Pool[nodeN].nxt = -1;
    return nodeN;
}

// 노드 해제
void dealloc(int nodeN) {
    freeIdxPool[++freeIdx] = nodeN; // 0번을 비우기 위해 증가 후 저장
}

// 지형 차이를 해시 키로 변환 (123 -> 1*100 + 2*10 + 3)
int getHash(int lengths[], int M) {
    int h = 0;
    for (int i = 0; i < M - 1; i++) {
        h = h * 10 + (lengths[i + 1] - lengths[i] + 5); // 음수 방지를 위해 +5 offset (선택사항)
    }
    return h;
}


// init에서 가로 세로 방향으로 1~4칸까지의 차이를 저장한 linked list를 담은 DAT배열 2개를 만들어둔다.
void init(int N, int mMap[20][20]) {
    // 초기화
    poolIdx = 0;
    freeIdx = 0;
    for (int i = 0; i < MAX_HASH; i++) rowDAT[i] = colDAT[i] = -1;

    // 가로 방향 전수 조사 (M=2~5 고려 가능하게 설계)
    for (int r = 0; r < N; r++) {
        for (int c = 0; c <= N - 2; c++) {
            // 모든 가능한 길이(2~5)에 대해 미리 해싱할 수도 있지만,
            // 보통 문제의 M값에 맞춰 조회합니다. 여기선 예시로 고정 길이 처리 로직 개념만 작성.
        }
    }
}




// 150,000 -> 12,000,000 / 150,000 = 80
// n은 [5, 20] 즉 최대 O(n) 높은 확률로 O(1)

// init에서 가로 세로 방향으로 1~4칸까지의 차이를 저장한 linked list를 담은 DAT배열 2개를 만들어둔다.
// 그리고 만들어둔 DAT배열에서 바로 idx 로 조회한다.
// 예를 들어 213의 경우 가로에서 213, 312를 가진 놈을 찾는다.
//
int numberOfCandidate(int M, int mStructure[5]){
    // 그냥 4방향 전수조사 하면 4*N^2 -> 안됨
    return 0;

    ㅘㅓㅣ
}

/*
 20 * 20 * 4 = 1600 * 150000

*/

int maxArea(int M, int mStructure[5], int mSeaLevel){

    return 0;
}
/////////////////////////////////////////////////////////////////////////

static int mMap[20][20];
static int mStructure[5];

static bool run()
{
    int numQuery;
    int N, M, mSeaLevel;
    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
            case CMD_INIT:
                scanf("%d", &N);
                for (int j = 0; j < N; j++)
                    for (int k = 0; k < N; k++)
                        scanf("%d", &mMap[j][k]);
                init(N, mMap);
                isCorrect = true;
                break;
            case CMD_NUMBER_OF_CANDIDATE:
                scanf("%d", &M);
                for (int j = 0; j < M; j++)
                    scanf("%d", &mStructure[j]);
                userAns = numberOfCandidate(M, mStructure);
                scanf("%d", &ans);
                if (userAns != ans)
                {
                    isCorrect = false;
                }
                break;
            case CMD_MAX_AREA:
                scanf("%d", &M);
                for (int j = 0; j < M; j++)
                    scanf("%d", &mStructure[j]);
                scanf("%d", &mSeaLevel);
                userAns = maxArea(M, mStructure, mSeaLevel);
                scanf("%d", &ans);
                if (userAns != ans)
                {
                    isCorrect = false;
                }
                break;
            default:
                isCorrect = false;
                break;
        }
    }
    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}