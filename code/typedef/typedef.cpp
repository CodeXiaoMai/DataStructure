# include <stdio.h>

typedef int ZHANGSAN;	//Ϊint�����¶���һ�����֣�ZHANGSAN�ȼ���int

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}ST;

void main() {
	int i = 10; // �ȼ��� ZAHNGSAN i = 10;
	ZHANGSAN j = 20;
	printf("%d\n", j);

	struct Student st; // �ȼ���ST st;
	struct Student * ps = &st; // �ȼ���ST *PS;
	ST st2;
	st2.sid = 200;
	printf("%d\n", st2.sid);
}