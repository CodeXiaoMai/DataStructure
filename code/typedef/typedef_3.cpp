# include <stdio.h>

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}* PSTU, STU; // 等价于ST代表了struct Student, PST 代表了struct Student *

void main() {
	STU st;	// struct Student st;
	PSTU ps = &st;	//	struct Student * ps = &st;	
	ps->sid = 99;
	printf("%d\n", ps->sid);
}