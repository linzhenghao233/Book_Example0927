#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
typedef int datatype;

//����˳��ջ�Ľṹ������ 
typedef struct {
	datatype stack[Maxsize];
	int top;	//ջ��ָ�� 
}SeqStack;

SeqStack* s;

//����һ����ջ
SeqStack* InitStack() {	//����ֵ��SeqStack���͵�ָ�� 
	SeqStack* s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	if (!s) {	//��ʾs��Ϊ�� 
		printf("�ռ䲻��");
		return NULL;
	}
	else {
		s->top = -1;
	}

	return s;
}

//��ջ��Ԫ��
SeqStack* Push(SeqStack* s, datatype x) {
	//��Ҫ�ж�ջ�Ƿ�Ϊ��
	if (s->top == Maxsize - 1) {
		printf("\nջ������\n");
		return NULL;
	}
	else {
		s->top++;
		s->stack[s->top] = x;
		return s;
	}
}

//ȡջ��Ԫ��
datatype GetTop(SeqStack* s) {
	//��Ҫ�ж�ջ�Ƿ�Ϊ��
	if (s->top == -1) {
		printf("\nջ�ǿյ�\n");
		return 0;
	}
	else
		return s->stack[s->top];
}

//��ջ
datatype Pop(SeqStack* s) {
	//��Ҫ�ж�ջ�Ƿ�Ϊ��
	if (s->top == -1) {
		printf("\nջ�ǿյ�\n");
		return 0;
	}
	else {
		s->top--;
		return s->stack[s->top];
	}
}

//�ж��Ƿ��ջ
int StackEmpty(SeqStack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

//��ӡջ��
void display(SeqStack* s) {
	int temp = s->top;
	if (s->top == -1)
		printf("�Ǹ���ջ\n");
	else {
		while (temp != -1) {
			printf("%d->", s->stack[temp]);
			temp--;
		}
	}
}

//����main����
int main(void) {
	int a[6] = { 3, 7, 4, 12, 31, 15 }, i;
	SeqStack* p;	//˳��ջָ��
	//�����ջ 
	p = InitStack();
	//��ջ
	for (i = 0; i < 6; i++)
		Push(p, a[i]);
	//��ӡջ��
	display(p);
	//��ջ
	Push(p, 100);
	display(p);
	Pop(p);
	Pop(p);
	//�ж��Ƿ�Ϊ��
	while (!StackEmpty(p))
		printf("%4d", Pop(p));
}