# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Queue {
	int * pBase;
	int front;
	int rear;
} QUEUE, * PQUEUE;

void init (PQUEUE);

bool isFull (PQUEUE);

bool isEmpty (PQUEUE);

/**
 * 入队
 */

bool enQueue (PQUEUE, int);

bool outQueue (PQUEUE, int *);

void traverseQueue (PQUEUE); 

void main() {
	Queue Q;
	init(&Q);
	int val;

	enQueue(&Q, 1);
	enQueue(&Q, 2);
	enQueue(&Q, 3);
	enQueue(&Q, 4);
	enQueue(&Q, 5);
	enQueue(&Q, 6);
	enQueue(&Q, 7);
	enQueue(&Q, 8);
	traverseQueue(&Q);
	if (outQueue(&Q, &val)) {
		printf("%d出队成功\n", val);
	} else {
		printf("%d出队失败\n");
	}
	traverseQueue(&Q);
	return;
}

void init (PQUEUE pQ) {
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	if (NULL == pQ->pBase) {
		printf("动态内存分配失败\n");
		exit(-1);
	}
	pQ->front = 0;
	pQ->rear = 0;
}

bool enQueue (PQUEUE pQ, int val) {
	if (isFull(pQ)) {
		return false;
	} else {
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
}

bool isFull (PQUEUE pQ) {
	if ((pQ->rear + 1) % 6 == pQ->front) {
		return true;
	} else {
		return false;
	}
}

void traverseQueue (PQUEUE pQ) {
	int i = pQ->front;
	while (i != pQ->rear) {
		printf("%d ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;
}

bool outQueue (PQUEUE pQ, int * pVal) {
	if (isEmpty(pQ)) {
		return false;
	}
	*pVal = pQ->pBase[pQ->front];
	pQ->front = (pQ->front + 1) % 6;
	return true;
}

bool isEmpty (PQUEUE pQ) {
	if (pQ->front == pQ->rear) {
		return true;
	}
	return false;
}