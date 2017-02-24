# include <stdio.h>
# include <malloc.h> // ������malloc����
# include <stdlib.h> // ������exit����

struct Arr{
	// �洢���������һ��Ԫ�صĵ�ַ
	int * pBase;
	// �����������ɵ����Ԫ�صĸ���
	int len;
	// ��ǰ������ЧԪ�صĸ���
	int cnt;
	// �Զ���������
	// int increment;
};

void init(struct Arr * pArr, int length);

// ׷��
bool append(struct Arr *pArr);

// ����
bool insert(struct Arr *pArr);

// ɾ��
bool deleteArr(struct Arr *pArr);

int get();

bool isEmpty(struct Arr *pArr);

bool isFull(struct Arr *pArr);

void sort(struct Arr *pArr);

void show(struct Arr *pArr);

// ����
void inversion();

void main(void){
	struct Arr arr;
	init(&arr, 6);
	show(&arr);
}

void init(struct Arr * pArr, int length){
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase) {
		printf("��̬�ڴ����ʧ�ܣ�\n");
		// ��ֹ��������
		exit(-1);
	} else {
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

bool isEmpty(struct Arr *pArr) {
	if (NULL == pArr || 0 == pArr->cnt) {
		return true;
	} else {
		return false;
	}
}

void show(struct Arr *pArr) {
	if (isEmpty(pArr)) {
		printf("����Ϊ�գ�\n");
	} else{
		for (int i = 0; i < pArr->cnt; ++i) {
			printf("%d", pArr->pBase[i]);
		}
		printf("\n");
	}
}