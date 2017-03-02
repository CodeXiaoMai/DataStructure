# include <stdio.h>

typedef int ZHANGSAN;	//为int再重新多起一个名字，ZHANGSAN等价于int

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}ST;

void main() {
	int i = 10; // 等价于 ZAHNGSAN i = 10;
	ZHANGSAN j = 20;
	printf("%d\n", j);

	struct Student st; // 等价于ST st;
	struct Student * ps = &st; // 等价于ST *PS;
	ST st2;
	st2.sid = 200;
	printf("%d\n", st2.sid);
}