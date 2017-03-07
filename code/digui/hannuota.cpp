# include <stdio.h>

/**
 * �Ȱ�A�����ϵ�ǰn-1�����ӽ���C�ƶ���B
 * ��A�����ϵĵ�n������ֱ���ƶ���C
 * ��B�����ϵ�n-1�����ӽ���A�ƶ���C
 */

void hannuota (int n, char a, char b, char c) {
	if (1 == n) {
		// ���ֻ��һ�����ӣ�ֱ�Ӵ�a�ƶ���c
		printf("�����Ϊ%d������ֱ�Ӵ�%c�ƶ���%c\n", n, a, c);
		return;
	} else {
		/* �Ƚ�a�е�ǰn - 1 �����ӽ���c�ƶ���b
		 * ֱ�ӽ�a�еĵ�n�������ƶ���c
		 * ��b�е�n-1�����ӽ���a�ƶ���c
		 */
		hannuota(n - 1, a, c, b);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�ƶ���%c\n", n, a, c);
		hannuota(n - 1, b, a, c);
		return;
	}
}

void main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ���\n");
	scanf("%d", &n);
	hannuota(n, ch1, ch2, ch3);
	return;
}