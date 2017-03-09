# include <stdio.h>

/**
 * �ڶ���������ʾ��һ���������±�
 * ������������ʾ���һ���������±�
 */
void quickSort(int *, int, int);

int findPos(int *a, int low, int high);

void main() {
	int a[6] = {2, 1, 0, 5, 4, 3};
	quickSort(a, 0, 5);
	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void quickSort(int *a, int low, int high) {
	if (low >= high) return;
	int pos;
	if (low < high) {
		pos = findPos(a, low, high);
		quickSort(a, low, pos-1);
		quickSort(a, pos+1, high);
	}
}

int findPos(int *a, int low, int high) {
	int val = a[low];
	while (low < high) {
		while (low < high && a[high] >= val) {
			high --;
		}
		a[low] = a[high];
		while (low <high && a[low] <= val) {
			low++;
		}
		a[high] = a[low];
	}
	a[low] = val;
	return low; // ��return high;
}