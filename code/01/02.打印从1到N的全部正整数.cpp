# include <stdio.h>

void printN(int);

void main() {
	int n;
	scanf("%d", &n);
	printN(n);
}

/**
 * 循环实现，输入100000时正常运行
 */
void printN(int n) {
	int i;
	for (i = 1; i <= n; i++){
		printf("%d\n", i);
	}
}

/**
 * 递归实现，输入100000时直接挂掉
 */
void printN(int n) {
	if (n != 1) 
		printN(n - 1); 
	printf("%d\n", n);
}