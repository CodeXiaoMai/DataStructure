# 第一章 #
严蔚敏、吴伟民、高一凡、黄国瑜
## 数据结构概述 ##
我们如何把现实中大量而复杂的问题以特定的数据类型和特定的存储结构保存到主存储器（内存）中，以及在此基础上为实现某个功能（比如查找某个元素，删除某个元素，对所有元素进行排序）而执行的相应操作，这个相应的操作叫算法。

数据结构 = 个体 + 个体之间的关系

算法 = 对存储数据的操作

程序 = 数据结构（数据的存储） + 算法（数据的操作） + 可以被计算机执行的语言

## 衡量算法的标准 ##

1. 时间复杂度：
	程序大概执行的次数，而非执行的时间
2. 空间复杂度：
	算法执行过程大概所占的最大内存
3. 难易程度
4. 健壮性

## 预备知识 ##
1. 指针
	
	指针就是地址，地址就是指针

	指针的本质是一个操作受限的非负整数
	
	指针变量是存放内存单元地址的变量
	地址是内存单元的编号，从0开始的非负整数，0 —— FFFFFFFF （0到4G-1）

2. 指针的分类
3. 指针和数组
	
	指针和一维数组
	一维数组名是个指针常量，它存放的是一维数组第一个元素的地址，它的值不能被改变。	
	
	int a[5] = {1,2,3,4,5};
	
	a[3] <==> *(a + 3);

	a + i 的值是a + i * (a所指的变量所占的字节数)
    
	代码1：

		# include <stdio.h>
		
		void f(int i){
			i = 100;
		}
		
		void f(int *i) {	// 定义了一个形参，名字加i，类型为int * (整型变量的地址)
			*i = 100;
		}
		
		void main (){
			int i = 9;
			f(i);
			int j = 9;
			f(&j);
			printf("i = %d\nj = %d\n", i, j); // i = 9, j = 100
		}

	代码2：

		# include <stdio.h>
		void main () {
			int a[5] = {1,3,4,6,5};
			printf("%p\n", a + 1);	// %p打印地址
			printf("%p\n", a + 2);
			printf("%p\n", a + 3);		
			printf("%d\n", *a + 3); // *a + 3 = a[0] + 3;
		}

    代码3：

		# include <stdio.h>
		
		void Show_Array(int *p, int len){
			p[0] = -1;
			int i = 0;
			for (i = 0; i < len; i++) {
				printf("%d\n", p[i]);
			}
		}
		
		void main() {
			int a[5] = {1,2,3,4,5};
			Show_Array(a, 5);	// a <==> &a[0]
			printf("%d\n", a[0]);
		}
4. 结构体
 
	结构体是用户根据实际需要定义的复合数据类型

	代码1：

		# include <stdio.h>
		# include <string.h>
		
		/* 结构体 */
		struct Student {
			// 成员
			int sid;
			char name[200];
			int age;
		};	// 分号不能省
		
		void main(void) {
			struct Student st = {100, "张三", 39};
			st.sid = 99; // 第一种方式
		
			// 第二种方式
			struct Student * pst;
			pst = &st;
			// pst ->sid 代表pst所指向的结构体变量中的sid这个成员
			pst ->sid = 99;	//pst ->sid 等价于 (*pst).sid 等价于 st.sid
		
			printf("%d %s %d\n", st.sid, st.name, st.age);
			st.sid = 99;
			//st.name = "李四"; // error
			strcpy(st.name, "李四");
			st.age = 22;
			printf("%d %s %d\n", st.sid, st.name, st.age);
		}

	代码2：

		# include <stdio.h>
		# include <string.h>
		
		/* 结构体 */
		struct Student {
			// 成员
			int sid;
			char name[200];
			int age;
		};	// 分号不能省
		
		void f(struct Student *pst);
		
		void g(struct Student st);
		
		void g(struct Student *st);
		void main(void) {
			struct Student st;
			f(&st);
			// printf("%d %s %d", st.sid, st.name, st.age);
			g(st);
			g(&st);
		}
		
		/**
		 * 这种方式的耗内存，耗时间，不推荐
		 */
		void g(struct Student st) {
			printf("%d %s %d\n", st.sid, st.name, st.age);
		}
		
		/**
		 * 这种方式只传递4个字节的地址
		 */
		void g(struct Student *pst) {
			printf("%d %s %d\n", pst->sid, pst->name, pst->age);
		}
		
		void f(struct Student * pst) {
			(*pst).sid = 22;
			strcpy(pst ->name, "zhangsan");
			pst->age = 22;
		}
5. 动态内存分配与释放
6. 
		# include <stdio.h>
		# include <malloc.h>
	
		void main(void) {
		
			int a[5] = {4, 10, 2, 8, 6};
			int len;
			printf("请输入数组的长度 : len = ");
			scanf("%d", &len);
			// 手动分配的内存必须手动释放
			int * pArr = (int *) malloc(sizeof(int) * len);
		
			//*pArr = 4; // a[0] = 4;
			//pArr[1] = 10;
			for (int i = 0; i < len; ++i)
				scanf("%d", &pArr[i]);
		
			for (i = 0; i < len; ++i)
				printf("%d\n", *(pArr + i));
		
			// 把pArr所代表的动态分配的内存释放
			free(pArr);
		}

	跨函数使用内存

		/**
		 * 跨函数使用内存
		 */
		
		# include <stdio.h>
		# include <malloc.h>
		
		struct Student {
			int sid;
			int age;
		};
		
		struct Student * createStudent();
		
		void showStudent(struct Student *);
		
		void main(){
			struct Student * ps;
			
			ps = createStudent();
			showStudent(ps);
		}
		
		struct Student * createStudent(){
			struct Student * p = (struct Student *)malloc(sizeof(struct Student));
			p->sid = 10;
			p->age = 99;
			return p;
		}
		
		void showStudent(struct Student * pst){
			printf("%d %d\n", pst->sid, pst->age);
		}