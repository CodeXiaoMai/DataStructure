# include <stdio.h>

void printN(int);

void main() {
	int n;
	scanf("%d", &n);
	printN(n);
}

/**
 * ѭ��ʵ�֣�����100000ʱ��������
 */
void printN(int n) {
	int i;
	for (i = 1; i <= n; i++){
		printf("%d\n", i);
	}
}

/**
 * �ݹ�ʵ�֣�����100000ʱֱ�ӹҵ�
 */
void printN(int n) {
	if (n != 1) 
		printN(n - 1); 
	printf("%d\n", n);
}