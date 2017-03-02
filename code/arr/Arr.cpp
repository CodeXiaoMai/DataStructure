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
bool append(struct Arr *pArr, int val);

/* ����
 * pos��ֵ�±��1��ʼ����ʾ�ڼ���Ԫ�ص�ǰ�����
 */
bool insert(struct Arr *pArr, int pos, int val);

// ɾ��
bool deleteArr(struct Arr *pArr, int pos, int *pVal);

int get();

bool isEmpty(struct Arr *pArr);

bool isFull(struct Arr *pArr);

void sort(struct Arr *pArr);

void show(struct Arr *pArr);

// ����
void inversion(struct Arr *pArr);

void main(void){
	struct Arr arr;
	int val;

	init(&arr, 6);
	append(&arr, 1);
	append(&arr, 2);
	append(&arr, 3);
	append(&arr, 4);
	append(&arr, 5);
	//insert(&arr, 1, 99);
	insert(&arr, 8, 99);
	if (deleteArr(&arr, 3, &val)) {
		printf("ɾ��%d�ɹ���\n", val);
	} else {
		printf("ɾ��ʧ�ܣ�");
	}
	show(&arr);
	inversion(&arr);
	show(&arr);
	sort(&arr);
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
			printf("%d\t", pArr->pBase[i]);
		}
		printf("\n");
	}
}

bool append(struct Arr *pArr, int val) {
	if (isFull(pArr)) {
		return false;
	} else {
		pArr->pBase[(pArr->cnt)++] = val;
	}
}

bool isFull(struct Arr *pArr) {
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

bool insert(struct Arr *pArr, int pos, int val) {
	if (isFull(pArr)){
		return false;
	}
	if (pos < 1 || pos > pArr->cnt + 1) {
		return false;
	}
	for (int i = pArr->cnt - 1; i >= pos - 1; i--) {
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;
	return true;
}

bool deleteArr(struct Arr *pArr, int pos, int *pVal) {
	if (isEmpty(pArr))
		return false;
	if (pos < 1 || pos > pArr->cnt)
		return false;
	*pVal = pArr->pBase[pos - 1];
	for (int i = pos; i < pArr->cnt; i++) {
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

void inversion(struct Arr *pArr) {
	int i = 0;
	int j = pArr->cnt - 1;
	int temp;
	while (i < j) {
		temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
		i ++;
		j --;
	}
}

void sort(struct Arr * pArr) {
	int i, j, t;
	for (i = 0; i < pArr->cnt; i++) {
		for (j = i + 1; j < pArr->cnt; j++) {
			if (pArr->pBase[i] > pArr->pBase[j]) {
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}