# include <stdio.h>

typedef struct Student {
	int sid;
	char name[100];
	char sex;
}* PSTU, STU; // �ȼ���ST������struct Student, PST ������struct Student *

void main() {
	STU st;	// struct Student st;
	PSTU ps = &st;	//	struct Student * ps = &st;	
	ps->sid = 99;
	printf("%d\n", ps->sid);
}