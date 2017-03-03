# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Node {
	int data; // ������
	struct Node *pNext; // ָ����
}NODE, *PNODE;

// ����һ����ѭ�������������������ͷ�ڵ��ַ��ֵ��pHead
PNODE createList();

// ��������
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
		printf("����Ϊ��\n");
	} else {
		printf("����Ϊ��\n");
	}
	insert(pHead, 3, 8888);
	if (deleteList(pHead, 5, &val)) {
		printf("ɾ��%d�ɹ�\n", val);
	} else {
		printf("ɾ��ʧ��\n");
	}
	int len = length(pHead);
	printf("����%d\n", len);
	//sort(pHead);
	traverseList(pHead);
}

PNODE createList() {
	// ��Ч�ڵ�ĸ���
	int len;
	// ��ʱ����û������ֵ
	int val;

	// ������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		printf("�ڴ����ʧ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("������Ҫ��������ڵ�ĸ���\n");
	scanf("%d", &len);
	for (int i = 0; i < len; i++){
		printf("�������%d���ڵ��ֵ\n", i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL== pNew) {
			printf("�ڴ����ʧ��\n");
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
 * ��pHead��ָ������ĵ�post�ڵ��ǰ�����һ���µĽڵ�
 * pos��ֵ��1��ʼ
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
		printf("��̬�ڴ����ʧ��\n");
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