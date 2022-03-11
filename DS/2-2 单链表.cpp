//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//StudybarCommentEnd

void  Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitList_L(LinkList &L){//初始化单链表
	L=new LNode;
	L->next=NULL;
}

void ListInsert_L(LinkList &L,int i,ElemType e){//使用插入操作创建单链表
	ElemType j=0;
	LinkList p=L;
	LNode *s;
	while(p&&(j<i-1)){
		p=p->next;
		++j;
	}
	if(!p||(j>i-1)) Error("Position Error!");
	else{
		s=new LNode;
		s->data=e;
		s->next=p->next;
		p->next=s;
	}
}

void GetElem_L(LinkList L,int i,ElemType &e){//求出第1个元素
	LNode *p=L;
	p=L->next;
	ElemType j=1;
	while(p&&(j<i)){
		p=p->next;
		++j;	
	}
	if(!p||(j>i)) Error("Position Error!");
	else e=p->data;
}

int LocateElem_L(LinkList L,ElemType e){//求出给定元素的位置
	int i=1;
	LNode *p=L->next;
	while(p&&(p->data!=e)){
		p=p->next;
		i++;
	}
	if(p) return i; 
	else return 0; 
}

int PreElem_L(LinkList L,ElemType cur_e,ElemType &pre_e){//求出给定元素的前驱元素
	int n=1;
	LNode *p=L;
	while(p&&(p->next->data!=cur_e)){
		p=p->next;
		n++;
	}
	if(p==L) return 0;
	else {
		pre_e=p->data;
		return 1;
	}
}

int NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e){//求出给定元素的后继元素
	LNode* p=L;
	LNode* pre_p=p;
	p=p->next;
	int n=1;
	while(p){
		if(pre_p->data==cur_e){
			next_e=p->data;
			return n+1;
		}
		pre_p=p;
		p=p->next;
		n++;
	}
	return 0;
}

void ListDelete_L(LinkList &L,int i,ElemType &e){//删除第1个元素
	LNode *p=L,*q;
	ElemType j=0;
	while((p->next)&&(j<i-1)){
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1)) Error("Position Error!");
	q=p->next;
	e=p->data;
	p->next=q->next;
	delete q;
}

void TraverseList_L(LinkList L){//输出删除第1个元素后的单链表
	LNode *p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}

void DestroyList_L(LinkList &L){//销毁单链表
	LNode *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}	
}

void ClearList_L(LinkList &L){
	LNode *p=L->next;
	while(p){
		LNode *q=p;
		p=p->next;
		delete q;
	} 
	L->next=NULL;
}

int ListLength_L(LinkList L){
	LNode *p=L;
	int length=0;
	while(p->next){
		length++;
		p=p->next;
	}
	return length;
}
	
//StudybarCommentBegin
int main()
{
	LinkList L;
	ElemType x,e,elem;
	int i;

	InitList_L(L);
	if(L)  printf("InitList_L success\n");

	printf("Create_List:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&elem);
		ListInsert_L(L,i+1,elem);
	}
	
	GetElem_L(L,1,e);
	printf("The first element is %d\n",e);
		
	printf("Enter the element you want to find:");
	scanf("%d",&x);
	if(!LocateElem_L(L,x))
		printf("Element %d is not exist\n",x);	
	else
	{
		printf("The %d at %d\n", x,LocateElem_L(L,x));
		if(PreElem_L(L,x,e))
			printf("The %d's previous element is %d\n",x,e);
		else 
			printf("The %d's previous element is not exist\n",x);	
		if(NextElem_L(L,x,e))
			printf("The %d's next element is %d\n",x,e);
		else
			printf("The %d's next element is not exist\n",x);	
	}

	ListDelete_L(L,1,e);
	printf("After deleting the first element, List:");
	TraverseList_L(L);
	
	DestroyList_L(L);
	if(!L)  printf("\nDestroyList_L success\n");	
	return 0;
}
//StudybarCommentEnd

/*
void CreateList_L(LinkList &L,int n){
//逆向建立单链表 
	InitList_L(L);
	for(i=n;i>0;i--){
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}
		
*/
/*
	void Connect_CL(LinkList &La,LinkList Lb) {
	// La和Lb是两个仅设尾指针的循环链表，将Lb链接到La之后
		p=La->next;// p指向La的头结点
		La->next=Lb->next->next; // 将Lb链接到La之后
		delete Lb->next; // 释放Lb的头结点
		Lb->next=p; // 链接之后构成循环
		La=Lb；// 重置尾指针
	} // Connect_CL 
*/

/*
typedef struct LNode{           //结点类型定义 
	ElemType  data;           //结点的数据域 
	Struct  LNode   *next;     //结点的指针域 
}LNode; 
typedef  LNode  *LinkList; 
//以上为定义表结构

LinkList Invert_L( LinkList L ){
	//逆置单链表L
	LNode *p ,*q ;//设置两个临时指针变量
	if( L&&L->next){ 
		//当链表不是空表或单结点时，将链表中的除头结点外的所有结点顺着链表指针，由前往后将每个结点依次从链表中摘下，作为第一个结点插入到带头结点链表中。这样就可以得到逆置的链表。
		L = L->next;
		p = L;
		q = p->next;
		p -> next = NULL; //将开始结点变成带头结点链表的终端结点，原来的第二个结点成为新的无头链表的开始结点
		
		while (q){ 
			//每次循环将无头结点链的后一个结点变成带头结点链的开始结点
			p = q; 
			q = q-> next ; 
			p->next = L;
			L = p;
		}
		return L;
	}
	return L; //如是空表或单结点表，直接返回头指针。
	//当链表为空表或只有一个结点时，该链表的逆置链表与原表相同。
}
//Invert_L
*/
