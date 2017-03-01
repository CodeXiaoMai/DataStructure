# 链表准备知识 #

## typedef ##

代码1

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

代码2

	# include <stdio.h>
	
	typedef struct Student {
		int sid;
		char name[100];
		char sex;
	}* PST; // PST 等价于struct Student *
	
	void main() {
		struct Student st;
		PST ps = &st;
		ps->sid = 99;
		printf("%d\n", ps->sid);
	}

代码3

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