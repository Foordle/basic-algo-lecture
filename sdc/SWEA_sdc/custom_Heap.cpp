#include <iostream>
#define MAX_HEAP 200005

struct Node {
    int id;
    int dist;

    bool operator<(const Node &nxt) const {
        if (dist != nxt.dist) return dist < nxt.dist;
        return id < nxt.id;
    }
};


struct Heap {
    Node heap[MAX_HEAP];
    int heap_size;

    void init() {
        heap_size = 0; // 0 번은 비워둬야 p c 계산이 편해요
        // curIdx / 2       = parant
        // curIdx * 2       = child1
        // curIdx * 2 + 1   = child2
    }

    // push는 가장 아래에 넣음
    void heap_push(Node data) {
        ++heap_size;
        int curIdx = heap_size;

        // top까지 이동
        while (curIdx > 1) {
            int pIdx = curIdx/2;
            if (data < heap[pIdx]) { // 부모가 나보다 우선순위가 낮다면
                heap[curIdx] = heap[pIdx];
                curIdx = pIdx;
            }
            else {
                break;
            }
        }
        heap[curIdx] = data;
    }

    Node heap_pop() {
        Node popNode = heap[1];
        Node lastNode= heap[heap_size];
        --heap_size;

        if (heap_size == 0) {
            return popNode;
        }

        int curIdx = 1;
        // pop은 위에서 부터 시작

        while (curIdx * 2 <= heap_size) {
            int childIdx = curIdx * 2;
            // 오른쪽 자식이 있는데 오른쪽 자식이 더 우선순위가 높다면
            if (childIdx + 1 <= heap_size && heap[childIdx + 1] < heap[childIdx]) {
                ++childIdx; // childIdx = childIdx + 1; 오른쪽 자식으로 바꾸는거임
            }
            // prooning, 일정 서브트리의 값이 마지막 값보다 낮은 경우로 왕왕
            if (!(heap[childIdx] < lastNode)) {
                break;
            }

            // 1부터 한칸씩 위로 땡김
            heap[curIdx] = heap[childIdx];
            curIdx = childIdx;

        }

        // 마지막 처리
        heap[curIdx] = lastNode;
        return popNode;
    }


};