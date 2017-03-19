# include <stdio.h>
# include <time.h>
# include <math.h>

// 多项式最大项数
#define MAXN 10
// 被测函数最大重复调用次数
#define MAXK 1e7

// 定义开始和结束时间
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

	/* 不在测试范围内的准备工作写在clock()调用之前*/
	/*
	 * clock()：捕捉从程序开始运行,到clock()被调用时所耗费的时间。
	 * 这个时间单位是clock tick，即“时钟打点”。
	 */
	start = clock();	/* 开始计时 */
	for (i = 0; i < MAXK; i++)
		f1(MAXN - 1, a, 1.1);
	stop = clock();
	/* 计算运行时间 */
	/**
	 * 常数CLK_TCK(或CLOCKS_PER_SEC)：机器时钟每秒所走的时钟打点数。
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