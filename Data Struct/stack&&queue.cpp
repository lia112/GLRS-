#include<iostream>
#include<algorithm>
#include<cstring>
#include <random>
#include <chrono>
#include<math.h>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<stack>
#include<Windows.h>

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


typedef struct Stack { //单链表
	int key;
	struct Stack* next;
}Stack;


typedef struct que { //单链表
	int key;
	struct que* next;
}que;

//结构体
void Stack_empty(Stack* s) {
	if (!s)cout << "EMPTY!!!";
	else cout << "NOT EMPTY";
}

Stack* Push(Stack* s, int a) {
	Stack* node = (Stack*)malloc(sizeof(Stack));
	node->key = a;
	node->next = s;
	s = node;
	return s;
}

Stack* Pop(Stack* s) {
	if (!s)cout << "ERROR!" << endl;
	else {
		Stack* p = s;
		s = s->next;//pop
		cout << p->key;//输出栈顶元素
		if (!s)cout << "EMPTY";
		else cout << "新的栈顶为" << s->key;
	}
	return s;
}

//数组入栈
int push(int* a,int top,int elem){
    a[top++]=elem;
    return top;
}
//数据元素出栈
int pop(int * a,int top){
    if (top==0) {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%d\n",a[top]);
    top--;
    return top;
}


typedef struct que { //单链表
	int key;
	struct que* next;
}que;


//利用数组
int Enqueue_arr(int* q, int x,int tail) {  
	q[tail++] = x;
	return tail;
}

void Delqueue_arr(int* q, int tail, int *head) {
	while (*head != tail) {
		cout << q[*head];
		*head++;
	}
}

//定义结构体进行操作
que* createque() {
	que* q = (que*)malloc(sizeof(que));
	q->next = NULL;
	return q;
}

que* ENque(que* q, int data) {
	que* node = (que*)malloc(sizeof(que));
	node->key = data;
	node->next = NULL;
	q->next = node;
	q = node;
	return q;
}

que* DELque(que* top, que* rear) {
	if(top->next == NULL) {
		printf("\n队列为空");
		return rear;
	}
	que* p = top->next;
	printf("%d ", p->key);
	top->next = p->next;
	if (rear == p) {
		rear = top;
	}
	free(p);
	return rear;
}




int main() {
	Stack* sta = NULL;
	for (int i = 0; i < 100000; i++) {
		sta = Push(sta, i);
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	for (int i = 0; i < 100000; i++) {
		sta = Pop(sta);
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "运行时间：" << time * 1000 << "ms" << endl;
	return 0;
}


//使用定长数组实现速度会略快一些，是否是动态分配内存时所消耗的，需要尝试
