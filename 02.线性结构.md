# 线性结构 #

> 把所有的结点用一根直线连接起来

## 连续存储（数组） ##

什么叫数组:元素类型相同，大小相等

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
    bool append(struct Arr *pArr, int val);
    
    /* 插入
     * pos的值下标从1开始，表示第几个元素的前面插入
     */
    bool insert(struct Arr *pArr, int pos, int val);
    
    // 删除
    bool deleteArr(struct Arr *pArr, int pos, int *pVal);
    
    int get();
    
    bool isEmpty(struct Arr *pArr);
    
    bool isFull(struct Arr *pArr);
    
    void sort(struct Arr *pArr);
    
    void show(struct Arr *pArr);
    
    // 倒置
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
    		printf("删除%d成功！\n", val);
    	} else {
    		printf("删除失败！");
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
			return true;
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