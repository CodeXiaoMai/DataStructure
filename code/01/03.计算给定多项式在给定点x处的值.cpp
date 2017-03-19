# include <stdio.h>
# include <time.h>
# include <math.h>

// ����ʽ�������
#define MAXN 10
// ���⺯������ظ����ô���
#define MAXK 1e7

// ���忪ʼ�ͽ���ʱ��
clock_t start, stop;

double duration;


double f1(int, double[], double);

double f2(int, double[], double);

void main() {
	int i;
	double a[MAXN];
	for (i = 0; i < MAXN; i++) {
		a[i] = (double) i;
	}

	/* ���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ*/
	/*
	 * clock()����׽�ӳ���ʼ����,��clock()������ʱ���ķѵ�ʱ�䡣
	 * ���ʱ�䵥λ��clock tick������ʱ�Ӵ�㡱��
	 */
	start = clock();	/* ��ʼ��ʱ */
	for (i = 0; i < MAXK; i++)
		f1(MAXN - 1, a, 1.1);
	stop = clock();
	/* ��������ʱ�� */
	/**
	 * ����CLK_TCK(��CLOCKS_PER_SEC)������ʱ��ÿ�����ߵ�ʱ�Ӵ������
	 */
	duration = ((double)(stop - start)) / CLK_TCK / MAXK;
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);


	start = clock();
	for (i = 0; i < MAXK; i++)
		f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK / MAXK;
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);
}

double f1(int n, double a[], double x) {
	int i;
	double p = a[0];
	for ( i = 1; i <= n; i++ ) {
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2(int n, double a[], double x) {
	int i;
	double p = a[0];
	for (i = n; i > 0; i--) {
		p = a[i-1] + x * p;
	}
	return p;
}