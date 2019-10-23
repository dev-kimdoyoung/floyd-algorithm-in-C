#include <stdio.h>
#include "definefunction.h"

int main() {
    // input.txt 파일을 통해 노드 개수와 노드 가중치를 입력받음
    freopen("./input.txt", "rt", stdin);

    // 가중치를 담을 2차원 배열을 노드 개수만큼 생성
    int nodeWeight[SIZE + 1][SIZE + 1] = {0, };
    
    // 노드 가중치 입력
    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            scanf("%d", &nodeWeight[i][j]);
        }
    }

    // Shortest Path를 담을 2차원 배열 선언
    int calculatedPathMatrix[SIZE + 1][SIZE + 1] = {0, };

    int startNodeNumber = 2;
    int searchNodeNumber = 5;
    scanf("%d", &startNodeNumber);
    scanf("%d", &searchNodeNumber);

    floyd(nodeWeight, calculatedPathMatrix, startNodeNumber, searchNodeNumber);

    return 0;
}

int outputLowNodeWeight(const int node1, const int node2) {
    if(node1 > node2) {
        return node2;

    } else if(node1 < node2) {
        return node1;

    } else if (node1 == node2) {
        return node1;
    }
}

_Bool floyd(int nodeWeight[][SIZE + 1], int calculatedPathMatrix[][SIZE + 1], 
            const int startNodeNumber, const int searchNodeNumber) {

    calculatedPathMatrix = nodeWeight;

    for(int k = 1; k <= SIZE; k++) {
        for(int i = 1; i <= SIZE; i++) {
            for(int j = 1; j <= SIZE; j++) {
                if(i == j) {
                    calculatedPathMatrix[i][j] = 0;
                } else if(i != j) {
                    calculatedPathMatrix[i][j] = outputLowNodeWeight(calculatedPathMatrix[i][j], 
                                                                     calculatedPathMatrix[i][k] + calculatedPathMatrix[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= SIZE; i++) {
        for(int j = 1; j <= SIZE; j++) {
            printf("%d ", calculatedPathMatrix[i][j]);
        }
        printf("\n");
    }

    printf("최적 경로 비용 : %d\n", calculatedPathMatrix[startNodeNumber][searchNodeNumber]);

    return true;

}