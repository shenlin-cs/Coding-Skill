#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//StudybarCommentBegin
#include<stdio.h>
#include<stdlib.h>


//���Ķ���������
typedef struct CSNode{
	int data;
	struct CSNode *firstchild,*nextslibing;
}CSNode,*CSTree;
//StudybarCommentEnd
typedef CSNode* ElemType;

#define QUEUE_MAX_SIZE 100
typedef struct{
	ElemType *elem;
	int front;
	int rear;
}SqQueue; 

void Error(char *s){
	printf("%s",s);
	exit(1);
}
void InitQueue_Sq(SqQueue &Q){
	Q.elem=new ElemType[QUEUE_MAX_SIZE];
	if(!Q.elem) Error("Overflow!");
	Q.front=Q.rear=0;
}

bool isempty(SqQueue &Q){
	if(Q.front==Q.rear) return 1;
	else return 0;
}
void EnQueue_Sq(SqQueue &Q,ElemType e){
	if(((Q.rear+1)%QUEUE_MAX_SIZE)==Q.front) Error("Queue Overflow!");
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%QUEUE_MAX_SIZE;
}

void DeQueue_Sq(SqQueue &Q,ElemType &e){
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%QUEUE_MAX_SIZE;
}
void CreatTree(CSTree &T){//�������Ķ������� 
	SqQueue Q;
	CSNode *p,*q,*r;
	int parent,child; 
	T=NULL;
	InitQueue_Sq(Q);
	
	for(cin>>parent>>child;child!=0;cin>>parent>>child){
		p=new CSNode;
		p->data=child;
		p->firstchild=p->nextslibing=NULL;
		EnQueue_Sq(Q,p);
		if(parent==-1) T=p;
		else{
			q=Q.elem[Q.front];
			while(q->data!=parent){
				DeQueue_Sq(Q,q);
				q=Q.elem[Q.front];
			}
			if(!(q->firstchild)){
				q->firstchild=p;
				r=p;
			}
			else{
				r->nextslibing=p;
				r=p;
			}
		}
		
	}
}


void PreOrderTraverse(CSTree T){//���������  
	if(T){
		cout<<T->data<<" ";
		PreOrderTraverse(T->firstchild);
		PreOrderTraverse(T->nextslibing);
	}  
}

void MiddleOrderTraverse(CSTree T){//��������� 
	if(T){
		MiddleOrderTraverse(T->firstchild);
		cout<<T->data<<" ";
		MiddleOrderTraverse(T->nextslibing);
	}
}

void FloorTraverse(CSTree T){//��������� 
	SqQueue Q;
	InitQueue_Sq(Q);
	EnQueue_Sq(Q,T);
	CSNode *p,*q;
	q=T;
	while(!isempty(Q)){
		while(q->nextslibing){
			q=q->nextslibing;
			EnQueue_Sq(Q,q);
		}
		DeQueue_Sq(Q,p);
		cout<<p->data<<" ";
		if(p->firstchild){
			EnQueue_Sq(Q,p->firstchild);
			q=p->firstchild;
		}
	}
}

//StudybarCommentBegin
int main()
{
	CSTree T;
	printf("�������Ķ�������0���������-1Ϊ�����ĸ���㣩��\n");
	CreatTree(T);
	printf("����������У�");
	PreOrderTraverse(T);
	printf("\n����������У�");
	MiddleOrderTraverse(T);
	printf("\n����������У�");
	FloorTraverse(T);
	printf("\n");
	return 0;
}
//StudybarCommentEnd
