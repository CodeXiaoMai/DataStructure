# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node {
	int data; // 数据域
	struct Node *pNext; // 指针域
}NODE, *PNODE;

// 创建一个非循环单链表，并将该链表的头节点地址赋值给pHead
PNODE createList();

// 遍历链表
void traverseList(PNODE pHead);

bool isEmpty(PNODE pHead);

int length(PNODE);

bool insert(PNODE, int, int);

bool deleteList(PNODE, int, int *);

void sort(PNODE);

void main() {
	PNODE pHead = NULL;
	int val;

	pHead = createList(); 
	traverseList(pHead);
	if (isEmpty(pHead)) {
		printf("链表为空\n");
	} else {
		printf("链表不为空\n");
	}
	insert(pHead, 3, 8888);
	if (deleteList(pHead, 5, &val)) {
		printf("删除%d成功\n", val);
	} else {
		printf("删除失败\n");
	}
	int len = length(pHead);
	printf("长度%d\n", len);
	//sort(pHead);
	traverseList(pHead);
}

PNODE createList() {
	// 有效节点的个数
	int len;
	// 临时存放用户输入的值
	int val;

	// 分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		printf("内存分配失败\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入要生成链表节点的个数\n");
	scanf("%d", &len);
	for (int i = 0; i < len; i++){
		printf("请输入第%d个节点的值\n", i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL== pNew) {
			printf("内存分配失败\n");
			exit(-1);
		} 
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

void traverseList(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (NULL != p) {
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool isEmpty(PNODE pHead) {
	if (NULL == pHead->pNext) {
		return true;
	} else {
		return false;
	}
}

int length(PNODE pHead) {
	PNODE p = pHead->pNext;
	int len = 0;
	while (NULL != p) {
		++len;
		p = p->pNext;
	}
	return len;
}

void sort(PNODE pHead) {
	int i, j, t;
	int len = length(pHead);
	PNODE p, q;
	for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext) {
		for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext) {
			if (p->data > q->data) {
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}

/**
 * 在pHead所指向链表的第post节点的前面插入一个新的节点
 * pos的值从1开始
 */
bool insert(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;

	while(NULL != p && i < pos - 1) {
		p = p->pNext;
		i++;
	}

	if (i > pos - 1 || NULL == p) {
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("动态内存分配失败\n");
		exit(-1);
	} 
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}

bool deleteList(PNODE pHead, int pos, int *pVal) {
	int i = 0;
	PNODE p = pHead;

	while(NULL != p->pNext && i < pos - 1) {
		p = p->pNext;
		i++;
	}

	if (i > pos - 1 || NULL == p->pNext) {
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->data;

	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}