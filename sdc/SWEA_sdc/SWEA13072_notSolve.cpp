/* B형관련 solution
 * 1. 숫자에서 수상스한 부분을 한번 체크해야함..
 *  ->  이 문제의 경우 팀갯수가 5개, 사람은 10만명? 오 좀 이상한데...? 이런느낌임..
 *  -> bestSoldier는 100번밖에? -> 이건 좀 들 신경쓸 수 밖에 없는 상황이라는 말임
*/



/* 내 풀이
 *  - 자료구조
 *      team별로 관리
 *          DAT 형식: ID를 주는데 써야지 뭐..
 *          pq ? -> bestSoldier에 강점을 주지만 여기서는 100번 밖에 호출 되지 않음
 *                  따라서 굳이 인거 같음, 차라리 sort를 하겠다.
 *          updateTeam에서 어차피  team전체 update필요하긴한데..
 *          그나마 최적화를 할라면  masking으로 updateTeam을 표시, 예외 id들 저장(stack) 이런식?
 *      결론
 *          1. 일단 TEAM별로 linked list에 넣어서 관리를 하되 updateTeam이 나오면 updateTeam check mask를 새김
 *             그리고 noUpdateSoldierStack을 비움, 따로 updateSoldier가 들어오면 noUpdateSoldierStack에 id를 넣고
 *             해당 soldier 값을 바꿈
 *
 *
 *
 */
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

extern void init();
extern void hire(int mID, int mTeam, int mScore);
extern void fire(int mID);
extern void updateSoldier(int mID, int mScore);
extern void updateTeam(int mTeam, int mChangeScore);
extern int bestSoldier(int mTeam);

/////////////////////////////////////////////////////////////////////////
#define MAX_ID 100001
#define MAX_NODE 1000005

struct Node { // linked list
    int id;
    int v; // 노드가 생성될 당시의 병사 버전 -> 낡은 버전은 거름, 이를 통해
    int next;
};

Node node_pool[MAX_NODE];
int node_cnt;

struct List { // 해당
    int head, tail;
};

List teams[6][6]; // teams[mTeam][mScore]
int soldier_v[MAX_ID]; // 병사의 현재 최신 버전
int soldier_team[MAX_ID]; // 병사의 현재 소속 팀

int get_node(int id, int v) {
    node_pool[node_cnt].id = id;
    node_pool[node_cnt].v = v;
    node_pool[node_cnt].next = -1;
    return node_cnt++;
}

void init() {
    node_cnt = 0;
    for (int t = 1; t <= 5; t++) {
        for (int s = 1; s <= 5; s++) {
            teams[t][s].head = teams[t][s].tail = -1;
        }
    }
    for (int i = 0; i < MAX_ID; i++) {
        soldier_v[i] = 0;
        soldier_team[i] = 0;
    }
}

void hire(int mID, int mTeam, int mScore) {
    soldier_v[mID]++; // 새로운 버전 생성
    soldier_team[mID] = mTeam;

    int nn = get_node(mID, soldier_v[mID]);
    if (teams[mTeam][mScore].head == -1) {
        teams[mTeam][mScore].head = nn;
    } else {
        node_pool[teams[mTeam][mScore].tail].next = nn;
    }
    teams[mTeam][mScore].tail = nn;
}

void fire(int mID) {
    soldier_team[mID] = 0; // 팀 소속을 없애 무효화
}

void updateSoldier(int mID, int mScore) {
    hire(mID, soldier_team[mID], mScore); // 새로운 버전으로 다시 hire
}

void updateTeam(int mTeam, int mChangeScore) {
    if (mChangeScore == 0) return;

    List next_teams[6];
    for (int i = 1; i <= 5; i++) next_teams[i].head = next_teams[i].tail = -1;

    for (int s = 1; s <= 5; s++) {
        int ns = s + mChangeScore;
        if (ns > 5) ns = 5;
        if (ns < 1) ns = 1;

        if (teams[mTeam][s].head == -1) continue;

        if (next_teams[ns].head == -1) {
            next_teams[ns].head = teams[mTeam][s].head;
        } else {
            node_pool[next_teams[ns].tail].next = teams[mTeam][s].head;
        }
        next_teams[ns].tail = teams[mTeam][s].tail;

        // 기존 리스트 비우기
        teams[mTeam][s].head = teams[mTeam][s].tail = -1;
    }

    for (int s = 1; s <= 5; s++) teams[mTeam][s] = next_teams[s];
}

int bestSoldier(int mTeam) {
    for (int s = 5; s >= 1; s--) {
        int curr = teams[mTeam][s].head;
        int max_id = -1;

        while (curr != -1) {
            Node& node = node_pool[curr];
            // 1. 해당 팀 소속인가? 2. 병사의 현재 버전과 노드의 버전이 일치하는가?
            if (soldier_team[node.id] == mTeam && soldier_v[node.id] == node.v) {
                if (node.id > max_id) max_id = node.id;
            }
            curr = node.next;
        }

        if (max_id != -1) return max_id;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

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
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
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
    freopen("SWEA13072.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}