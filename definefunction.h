#define SIZE 5

/*
 * define boolean
*/
#define true 1
#define false 0

/*
 *  function prototype
 */

// node1과 node2 최소값 return해주는 함수
int outputLowNodeWeight(const int node1, const int node2);

// floyd algorithm 구현
_Bool floyd(int nodeWeight[][SIZE + 1], int calculatedPathMatrix[][SIZE + 1], 
            const int startNodeNumber, const int searchNodeNumber);

