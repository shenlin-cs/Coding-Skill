//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX_SIZE 100;
typedef int ElemType;

//存储结构
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针
}LinkQueue;
//StudybarCommentEnd

void Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitQueue_L(LinkQueue &Q){//初始化链队列
	Q.front=Q.rear=new QNode;
	Q.front=Q.rear=NULL;
}
/*
	Q.data=new ElemType[QUEUE_MAX_SIZE];
	if(!Q.elem) Error("Overflow");
	Q.front=Q.rear=0;
*/

void EnQueue_L(LinkQueue &Q, ElemType e){//使用入队操作创建链队列
	QNode *p=new QNode;
	p->data=e;
	p->next=NULL;
	if(Q.front==Q.rear&&Q.front==NULL){
		Q.front=p;
		Q.rear=p;
	} 
	Q.rear->next=p;
	Q.rear=p;
}
/*
	if(((Q.rear+1)%QUEUE_MAX_SIZE)==Q.front) Error("Queue Overflow!");
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%Queue_Size;
*/

void GetHead_L(LinkQueue Q, ElemType &e){//取出队头元素
	if(Q.front->next==NULL) Error("Queue Empty!");
	e=Q.front->data;
}
/*
	if(Q.front==Q.rear) Error("Queue Empty!");
	e=Q.data[Q.front];
*/
void DeQueue_L(LinkQueue &Q, ElemType &e){//删除队头元素
	if(Q.front->next==NULL) Error("Queue Empty!");
	QNode *p=new QNode;
	p=Q.front;
	e=Q.front->data;
	Q.front=Q.front->next;
	if(Q.rear==p) Q.rear=Q.front;
	delete p;
}
/*
	if(Q.front==Q.rear) Error("Queue Empty!");
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%QUEUE_MAX_SIZE;
*/
int QueueLength_L(LinkQueue Q){
	QNode *p=Q.front;
	int length=0;
	while(p->next){
		length++;
		p=p->next;
	}
}
void TraverseQueue_L(LinkQueue Q){//输出删除队头元素后的链队列
	QNode *p=new QNode;
	p=Q.front;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}
/*
	int QueueLength_Sq(SqQueue Q){
		length=(Q.rear-Q.front+QUEUE_MAX_SIZE)%QUEUE_MAX_SIZE;
		return length;

	p=Q.front;
	length=0;
	while(p->next){
		length++;
		p=p->next;
	}
	return length;
*/
bool DestroyQueue_L(LinkQueue &Q){//销毁链队列
	QNode *p=new QNode;
	p=Q.front;
	while(Q.front){
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
	return (!Q.front);
}
/*
	delete[] Q.data;
	Q.front=Q.rear=0;
*///DestroyQueue_Sq

/*
	p=Q.front->next;
	while(p){
		q=p;
		p=p->next;
		delete p;
	}
	Q.front->next=NULL;
	Q.rear=Q.front;
*///clear_L

 
//StudybarCommentBegin
int main()
{
	LinkQueue Q;
	ElemType e,elem;
	int i;

	InitQueue_L(Q);
	printf("InitQueue_L success\n");

	printf("Create_Queue:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&elem);
		EnQueue_L(Q,elem);
	}
	
	GetHead_L(Q,e);
	printf("Header element is %d\n",e);
		
	DeQueue_L(Q,e);
	printf("After deleting Queue header element, List:");
	TraverseQueue_L(Q);
		
	if(DestroyQueue_L(Q))  printf("\nDestroyQueue_L success\n");
	return 0;
}
//StudybarCommentEnd

/*
	void SeeDoctor(){
		InitQueue_L(Q);
		flag=1;(接受患者)
		while(flag){
			cout<<"请输入命令"；
			cin>>ch;
			switch(ch){
				case'a':
					cout<<"病历号";cin>>n>>endl;
					EnQueue_L(Q,n);
					break;
				case'n':
					if(Q.front->next){
						DeQueue_L(Q,n);
						cout<<"病历号"<<n<<就诊
					}
					else cout<<"no"<<endl;
					break;
				case's':
					while(Q.front->next){
						DeQueue_L(Q,n); cout<<n<<" ";
					}
					cout<<今天不再接受；
					falg=0;
					break;
				default:
					cout<<不合法
			}
		}
	}
					 
*/
