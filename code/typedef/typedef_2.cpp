# include <stdio.h>

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}* PST; // PST �ȼ���struct Student *

void main() {
	struct Student st;
	PST ps = &st;
	ps->sid = 99;
	printf("%d\n", ps->sid);
}