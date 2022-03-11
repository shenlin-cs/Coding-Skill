#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//存储结构
typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
	
}DuLNode;
typedef DuLNode *DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//在双向链表L中第i个结点之前插入值为e的结点；
	p=GetElemP_DuL(L,i);
	if(p==NULL) Error("Position Error!");
	s=new DuLNode;
	s->data=e;
	s->prior=p->prior;
	s->next=p;
	p->prior->next=s;
	p->prior=s; 
}

DuLNode *GetElemP_DuL(DuLinkList L,int i){
	//返回双向链表L中第i个结点指针
	p=L->next;
	j=1;
	while((p!=L)&&(j<i)){
		p=p->next;
		++j;
	} 
	if(((p==L)&&(j!=i))||(j>i)) return NULL;
	return p;
}


void ListDelete_DuL(DuLinkList &L,int i,ElemType e){
	//用e返回双向链表L第i个结点数据域值并删除该结点；
	p=GetElemP_DuL(L,i);
	if(p==NULL) Error("Position Error!");
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
}
DuLNode *GetElemP_DuL(DuLinkList L,int i){
	//返回双向链表L中第i个结点指针
	p=L;
	j=0;
	while((p->next!=L)&&(j<i-1)){
		p=p->next;
		++j;
	} 
	if((p->next==L)||(j>i-1)) return NULL;
	return p->next;
}


