# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *pNext;
}NODE, * PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pStack);

void push(PSTACK, int);

bool pop(PSTACK, int *);

void traverse(PSTACK pS);

void clear(PSTACK pS);

void main() {
	STACK S;
	int val;
	init(&S);
	push(&S, 1);
	push(&S, 2);
	traverse(&S);
	clear(&S);
	traverse(&S);
	if (pop(&S, &val))
		printf("出栈的数据为%d\n", val);
	if (pop(&S, &val))
		printf("出栈的数据为%d\n", val);
	if (pop(&S, &val))
		printf("出栈的数据为%d\n", val);
	return;
}

void init(PSTACK pS) {
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("动态内存分配失败");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL;
}

void push(PSTACK pS, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return;
}

void traverse(PSTACK pS) {
	if (pS->pTop == pS->pBottom) {
		printf("栈为空\n");
		return;
	}
	PNODE p = pS->pTop;
	while (p != pS->pBottom) {
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool isEmpty(PSTACK pS) {
	if (pS->pTop == pS->pBottom) {
		return true;
	} else {
		return false;
	}
}

bool pop(PSTACK pS, int * pVal) {
	if (isEmpty(pS)) {
		return false;
	}

	PNODE r = pS->pTop;
	*pVal = r->data;
	pS->pTop = r->pNext;
	free(r);
	r = NULL;
	return true;
}

void clear(PSTACK pS) {
	if (isEmpty(pS)) {
		return;
	}

	PNODE r = pS->pTop;
	while (r != pS->pBottom) {
		pS->pTop = r->pNext;
		free(r);
		r = pS->pTop;
	}
}