#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
typedef int datatype;

//定义顺序栈的结构体类型 
typedef struct {
	datatype stack[Maxsize];
	int top;	//栈顶指针 
}SeqStack;

SeqStack* s;

//构造一个空栈
SeqStack* InitStack() {	//返回值玮SeqStack类型的指针 
	SeqStack* s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	if (!s) {	//表示s不为空 
		printf("空间不足");
		return NULL;
	}
	else {
		s->top = -1;
	}

	return s;
}

//入栈顶元素
SeqStack* Push(SeqStack* s, datatype x) {
	//需要判断栈是否为满
	if (s->top == Maxsize - 1) {
		printf("\n栈是满的\n");
		return NULL;
	}
	else {
		s->top++;
		s->stack[s->top] = x;
		return s;
	}
}

//取栈顶元素
datatype GetTop(SeqStack* s) {
	//需要判断栈是否为空
	if (s->top == -1) {
		printf("\n栈是空的\n");
		return 0;
	}
	else
		return s->stack[s->top];
}

//出栈
datatype Pop(SeqStack* s) {
	//需要判断栈是否为空
	if (s->top == -1) {
		printf("\n栈是空的\n");
		return 0;
	}
	else {
		s->top--;
		return s->stack[s->top];
	}
}

//判断是否空栈
int StackEmpty(SeqStack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

//打印栈表
void display(SeqStack* s) {
	int temp = s->top;
	if (s->top == -1)
		printf("是个空栈\n");
	else {
		while (temp != -1) {
			printf("%d->", s->stack[temp]);
			temp--;
		}
	}
}

//构造main函数
int main(void) {
	int a[6] = { 3, 7, 4, 12, 31, 15 }, i;
	SeqStack* p;	//顺序栈指针
	//构造空栈 
	p = InitStack();
	//入栈
	for (i = 0; i < 6; i++)
		Push(p, a[i]);
	//打印栈表
	display(p);
	//出栈
	Push(p, 100);
	display(p);
	Pop(p);
	Pop(p);
	//判断是否为空
	while (!StackEmpty(p))
		printf("%4d", Pop(p));
}