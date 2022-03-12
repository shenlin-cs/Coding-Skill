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
	printf("������Ҫ��������е����ݸ�����"); 
	scanf("%d",&count);
	printf("����������Ҫ��ӵ����ݣ�");
	for (int i=0;i<count;i++)
	{
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow��");
		scanf("%d",&number);
		p->data=number;
		p->next=NULL;
		head.rear->next=p;
		p->prior=head.rear;
		head.rear=p;
	}
	printf("����������ɡ�\n");
	return head;
}

void EnDQueue(LinkDQueue &Q, int e)
{
	int judge;
	DQueue *p=NULL;
	DQueue *q=NULL;
	printf("��ѡ��Ӷ˵�1���Ƕ˵�2��ӣ�");
	scanf("%d",&judge);
	switch (judge)
	{
	case 1:
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow��");
		p->data=e;
		p->next=NULL;
		Q.rear->next=p;
		p->prior=Q.rear;
		Q.rear=p;
		printf("�����ɣ�\n"); 
		break;
	case 2:
		p=(struct DQueue *)malloc(LEN);
		if(!p)
			Error("Overflow��");
		p->data=e;
		q=Q.front->next;
		Q.front->next=p;
		p->next=q;
		q->prior=p;
		p->prior=Q.front;
		printf("�����ɣ�\n"); 
		break;
	}
}

void DeDQueue(LinkDQueue &Q, int e)
{
	int judge;
	printf("��ѡ��Ӷ˵�1���Ƕ˵�2���ӣ�");
	scanf("%d",&judge);
	DQueue *p=NULL;
	DQueue *q=NULL;
	switch(judge)
	{
	case 1:
		if (Q.rear==NULL)
			Error("DQueue Empty��");
		p=Q.rear->prior;
		q=Q.rear;
		e=q->data;
		printf("������ɡ�\n");
		printf("�Ѿ����ӵ����ǣ�%d\n",e);
		p->next=NULL;
		Q.rear=p;
		if (Q.front==p)
			Q.front=Q.rear;
		delete q;
		break;
	case 2:
		if (Q.front->next==NULL)
			Error("DQueue Empty��");
		p=Q.front->next;
		e=p->data;
		printf("������ɡ�\n");
		printf("�Ѿ����ӵ����ǣ�%d\n",e);
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
	printf("��Ӷ˵�1���˵�2������У�\n"); 
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
	printf("����1������һ�����У��Ӷ˵�1���������������\n");
	LinkDQueue Q;
	Q=CreatDQueue();
	PrintDQueue(Q);
	
	int n;
	printf("����2.1����Ӷ˵�1��ӣ���������С�\n"); 
	printf("������Ҫ��ӵ�����");
	scanf("%d",&n);
	EnDQueue(Q, n);
	PrintDQueue(Q);
	printf("����2.2����Ӷ˵�2��ӣ���������С�\n"); 
	printf("������Ҫ��ӵ�����");
	scanf("%d",&n);
	EnDQueue(Q, n);
	PrintDQueue(Q);
	
	int m;
	printf("����3.1���Ӷ˵�1���ӣ��������ֵ��");
	DeDQueue(Q, m);
	PrintDQueue(Q);
	printf("����3.2���Ӷ˵�2���ӣ��������ֵ��");
	DeDQueue(Q, m);
	PrintDQueue(Q);
	
	return 0;
} 
