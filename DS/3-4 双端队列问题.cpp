#include<stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct DQueue)

typedef struct DQueue
{
	int data; 
	struct DQueue *prior;
	struct DQueue *next;
}DQueue, *DQueueptr;

typedef struct
{
	DQueueptr front;
	DQueueptr rear;
}LinkDQueue;

void Error(char *s)
{
	printf(s);
	exit(1);
}

LinkDQueue CreatDQueue()
{
	DQueue *p;
	LinkDQueue head;
	head.front=head.rear=(struct DQueue *)malloc(LEN);
	head.front->data=0;  
	head.front->next=NULL;
	head.rear->next=NULL;
	int count,number;
	printf("请输入要放入队列中的数据个数："); 
	scanf("%d",&count);
	printf("请依次输入要入队的数据：");
	for (int i=0;i<count;i++)
	{
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow！");
		scanf("%d",&number);
		p->data=number;
		p->next=NULL;
		head.rear->next=p;
		p->prior=head.rear;
		head.rear=p;
	}
	printf("创建队列完成。\n");
	return head;
}

void EnDQueue(LinkDQueue &Q, int e)
{
	int judge;
	DQueue *p=NULL;
	DQueue *q=NULL;
	printf("请选择从端点1还是端点2入队：");
	scanf("%d",&judge);
	switch (judge)
	{
	case 1:
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow！");
		p->data=e;
		p->next=NULL;
		Q.rear->next=p;
		p->prior=Q.rear;
		Q.rear=p;
		printf("入队完成！\n"); 
		break;
	case 2:
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow！");
		p->data=e;
		q=Q.front->next;
		Q.front->next=p;
		p->next=q;
		q->prior=p;
		p->prior=Q.front;
		printf("入队完成！\n"); 
		break;
	}
}

void DeDQueue(LinkDQueue &Q, int e)
{
	int judge;
	printf("请选择从端点1还是端点2出队：");
	scanf("%d",&judge);
	DQueue *p=NULL;
	DQueue *q=NULL;
	switch(judge)
	{
	case 1:
		if (Q.rear==NULL)
			Error("DQueue Empty！");
		p=Q.rear->prior;
		q=Q.rear;
		e=q->data;
		printf("出队完成。\n");
		printf("已经出队的数是：%d\n",e);
		p->next=NULL;
		Q.rear=p;
		if (Q.front==p)
			Q.front=Q.rear;
		delete q;
		break;
	case 2:
		if (Q.front->next==NULL)
			Error("DQueue Empty！");
		p=Q.front->next;
		e=p->data;
		printf("出队完成。\n");
		printf("已经出队的数是：%d\n",e);
		Q.front->next=p->next;
		p->next->prior=Q.front;
		if (Q.rear==p)
			Q.rear=Q.front;
		delete p; 
		break;
	}
}

void PrintDQueue(LinkDQueue &Q)
{
	printf("请从端点1到端点2输出队列：\n"); 
	DQueueptr p=Q.rear;  
    while(p!=Q.front)  
    {  
        printf("%d\n",p->data); 
        p=p->prior; 
    }
    printf("\n");
}
int main()
{
	printf("测试1：创建一个队列（从端点1插入数）并输出。\n");
	LinkDQueue Q;
	Q=CreatDQueue();
	PrintDQueue(Q);
	
	int n;
	printf("测试2.1：请从端点1入队，并输出队列。\n"); 
	printf("请输入要入队的数：");
	scanf("%d",&n);
	EnDQueue(Q, n);
	PrintDQueue(Q);
	printf("测试2.2：请从端点2入队，并输出队列。\n"); 
	printf("请输入要入队的数：");
	scanf("%d",&n);
	EnDQueue(Q, n);
	PrintDQueue(Q);
	
	int m;
	printf("测试3.1：从端点1出队，并输出其值。");
	DeDQueue(Q, m);
	PrintDQueue(Q);
	printf("测试3.2：从端点2出队，并输出其值。");
	DeDQueue(Q, m);
	PrintDQueue(Q);
	
	return 0;
} 
