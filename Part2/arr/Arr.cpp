# include <stdio.h>
# include <malloc.h> // 包含了malloc函数
# include <stdlib.h> // 包含了exit函数

struct Arr{
	// 存储的是数组第一个元素的地址
	int * pBase;
	// 数组所能容纳的最大元素的个数
	int len;
	// 当前数组有效元素的个数
	int cnt;
	// 自动增长因子
	// int increment;
};

void init(struct Arr * pArr, int length);

// 追加
bool append(struct Arr *pArr);

// 插入
bool insert(struct Arr *pArr);

// 删除
bool deleteArr(struct Arr *pArr);

int get();

bool isEmpty(struct Arr *pArr);

bool isFull(struct Arr *pArr);

void sort(struct Arr *pArr);

void show(struct Arr *pArr);

// 倒置
void inversion();

void main(void){
	struct Arr arr;
	init(&arr, 6);
	show(&arr);
}

void init(struct Arr * pArr, int length){
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase) {
		printf("动态内存分配失败！\n");
		// 终止整个程序
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
		printf("数组为空！\n");
	} else{
		for (int i = 0; i < pArr->cnt; ++i) {
			printf("%d", pArr->pBase[i]);
		}
		printf("\n");
	}
}