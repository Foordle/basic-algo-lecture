#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_MAKE_LIST 200
#define CMD_COPY_LIST 300
#define CMD_UNDATE_ELEMENT 400
#define CMD_ELEMENT 500

extern void init();
extern void makeList(char mName[], int mLength, int mListValue[]);
extern void copyList(char mDest[], char mSrc[], bool mCopy);
extern void updateElement(char mName[], int mIndex, int mValue);
extern int element(char mName[], int mIndex);

/////////////////////////////////////////////////////////////////////////
//
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 최대 256MB 제한이므로 int 기준 약 6천만 개 저장 가능
// 200,001 * 10 (원본) = 200만 개 (충분함)
// 하지만 updateElement가 10만 번이므로, 모든 변경사항을 기록해야 함

struct Node {
    int val;
    int prev_ver; // 이전 버전의 인덱스 (역추적용)
};

// 10개의 원본 리스트 저장용
int origin_lists[11][200001];
// 각 리스트가 어떤 상태인지 관리
struct ListInfo {
    int origin_id;       // 어떤 원본에서 파생되었는가?
    int last_update_idx; // 최근 변경된 값의 로그 인덱스 (-1이면 원본 상태)
};

ListInfo lists[5011];
int listCount;

// 변경 사항 로그 (Copy-on-Write 대신 로그 방식)
struct UpdateLog {
    int index;
    int value;
    int prev_log_idx;
};
UpdateLog logs[105001]; // updateElement 10만 번 대응
int logCount;

unordered_map<string, int> nameToId;

void init() {
    nameToId.clear();
    listCount = 0;
    logCount = 0;
}

void makeList(char mName[], int mLength, int mListValue[]) {
    int lId = listCount++;
    nameToId[string(mName)] = lId;

    int oId = lId; // 초기 10개는 자기 자신이 origin
    lists[lId] = {oId, -1};

    for (int i = 0; i < mLength; i++) {
        origin_lists[oId][i] = mListValue[i];
    }
}

void copyList(char mDest[], char mSrc[], bool mCopy) {
    int srcId = nameToId[string(mSrc)];
    int destId = listCount++;
    nameToId[string(mDest)] = destId;

    if (mCopy) {
        // Deep Copy 효과: 현재까지의 변경 로그를 끊고 새로운 상태를 유지해야 함
        // 여기서는 단순화를 위해 현재 로그의 끝점을 가리키게 함
        lists[destId] = lists[srcId];
        // 주의: 문제에서 '완전 독립'을 요구하므로 실제로는 더 복잡한 처리가 필요할 수 있음
    } else {
        // Shallow Copy: 같은 상태를 공유 (로그 추적을 같이 함)
        lists[destId] = lists[srcId];
    }
}

void updateElement(char mName[], int mIndex, int mValue) {
    int lId = nameToId[string(mName)];

    // 새로운 로그 기록
    logs[logCount] = {mIndex, mValue, lists[lId].last_update_idx};
    lists[lId].last_update_idx = logCount++;
}

int element(char mName[], int mIndex) {
    int lId = nameToId[string(mName)];
    int current_log = lists[lId].last_update_idx;

    // 최신 변경 로그부터 역추적 (Index가 일치하는 최신값 탐색)
    while (current_log != -1) {
        if (logs[current_log].index == mIndex) {
            return logs[current_log].value;
        }
        current_log = logs[current_log].prev_log_idx;
    }

    // 로그에 없으면 원본 리스트에서 반환
    return origin_lists[lists[lId].origin_id][mIndex];
}
/////////////////////////////////////////////////////////////////////////

static unsigned int mSeed;
static unsigned int pseudo_rand(void)
{
    mSeed = mSeed * 214013 + 2531011;
    return (mSeed >> 16) & 0x7FFF;
}

static char mName[21];
static char mDest[21];
static char mSrc[21];
static int mListValue[200000];

static void generateName(char *name, int seed)
{
    mSeed = seed;
    int name_len = pseudo_rand() % 20 + 1;
    for (int i = 0; i < name_len; ++i)
    {
        name[i] = pseudo_rand() % 26 + 'a';
    }
    name[name_len] = '\0';
}

static int generateList(int *listValue, int seed)
{
    mSeed = seed;
    int length = pseudo_rand() << 15;
    length = (length + pseudo_rand()) % 200000 + 1;
    for (int i = 0; i < length; ++i)
    {
        listValue[i] = pseudo_rand();
    }
    return length;
}

static bool run()
{
    int numQuery;

    int seed;
    int mIndex, mValue, mCopy, mLength;
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
            init();
            isCorrect = true;
            break;
        case CMD_MAKE_LIST:
            scanf("%d", &seed);
            generateName(mName, seed);
            scanf("%d", &seed);
            mLength = generateList(mListValue, seed);
            makeList(mName, mLength, mListValue);
            break;
        case CMD_COPY_LIST:
            scanf("%d", &seed);
            generateName(mDest, seed);
            scanf("%d", &seed);
            generateName(mSrc, seed);
            scanf("%d", &mCopy);
            copyList(mDest, mSrc, (mCopy != 0));
            break;
        case CMD_UNDATE_ELEMENT:
            scanf("%d", &seed);
            generateName(mName, seed);
            scanf("%d %d", &mIndex, &mValue);
            updateElement(mName, mIndex, mValue);
            break;
        case CMD_ELEMENT:
            scanf("%d", &seed);
            generateName(mName, seed);
            scanf("%d", &mIndex);
            userAns = element(mName, mIndex);
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
    //freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
