#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//�洢�ṹ
typedef struct DuLNode{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
	
}DuLNode;
typedef DuLNode *DuLinkList;

void ListInsert_DuL(DuLinkList &L,int i,ElemType e){
	//��˫������L�е�i�����֮ǰ����ֵΪe�Ľ�㣻
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
	//����˫������L�е�i�����ָ��
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
	//��e����˫������L��i�����������ֵ��ɾ���ý�㣻
	p=GetElemP_DuL(L,i);
	if(p==NULL) Error("Position Error!");
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	delete p;
}
DuLNode *GetElemP_DuL(DuLinkList L,int i){
	//����˫������L�е�i�����ָ��
	p=L;
	j=0;
	while((p->next!=L)&&(j<i-1)){
		p=p->next;
		++j;
	} 
	if((p->next==L)||(j>i-1)) return NULL;
	return p->next;
}


