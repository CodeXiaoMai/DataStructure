# include <stdio.h>

/**
 * 先把A柱子上的前n-1个盘子借助C移动到B
 * 将A柱子上的第n个盘子直接移动到C
 * 将B柱子上的n-1个盘子借助A移动到C
 */

void hannuota (int n, char a, char b, char c) {
	if (1 == n) {
		// 如果只有一个盘子，直接从a移动到c
		printf("将编号为%d的盘子直接从%c移动到%c\n", n, a, c);
		return;
	} else {
		/* 先将a中的前n - 1 个盘子借助c移动到b
		 * 直接将a中的第n个盘子移动到c
		 * 将b中的n-1个盘子借助a移动到c
		 */
		hannuota(n - 1, a, c, b);
		printf("将编号为%d的盘子直接从%c移动到%c\n", n, a, c);
		hannuota(n - 1, b, a, c);
		return;
	}
}

void main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入要移动盘子的个数\n");
	scanf("%d", &n);
	hannuota(n, ch1, ch2, ch3);
	return;
}