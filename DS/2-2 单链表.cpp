//StudybarCommentBegin
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//�洢�ṹ
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//StudybarCommentEnd

void  Error(char *s){
	printf("%s\n",s);
	exit(1);
}

void InitList_L(LinkList &L){//��ʼ��������
	L=new LNode;
	L->next=NULL;
}

void ListInsert_L(LinkList &L,int i,ElemType e){//ʹ�ò����������������
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

void GetElem_L(LinkList L,int i,ElemType &e){//�����1��Ԫ��
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

int LocateElem_L(LinkList L,ElemType e){//�������Ԫ�ص�λ��
	int i=1;
	LNode *p=L->next;
	while(p&&(p->data!=e)){
		p=p->next;
		i++;
	}
	if(p) return i; 
	else return 0; 
}

int PreElem_L(LinkList L,ElemType cur_e,ElemType &pre_e){//�������Ԫ�ص�ǰ��Ԫ��
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

int NextElem_L(LinkList L,ElemType cur_e,ElemType &next_e){//�������Ԫ�صĺ��Ԫ��
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

void ListDelete_L(LinkList &L,int i,ElemType &e){//ɾ����1��Ԫ��
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

void TraverseList_L(LinkList L){//���ɾ����1��Ԫ�غ�ĵ�����
	LNode *p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
}

void DestroyList_L(LinkList &L){//���ٵ�����
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
//������������ 
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
	// La��Lb����������βָ���ѭ��������Lb���ӵ�La֮��
		p=La->next;// pָ��La��ͷ���
		La->next=Lb->next->next; // ��Lb���ӵ�La֮��
		delete Lb->next; // �ͷ�Lb��ͷ���
		Lb->next=p; // ����֮�󹹳�ѭ��
		La=Lb��// ����βָ��
	} // Connect_CL 
*/

/*
typedef struct LNode{           //������Ͷ��� 
	ElemType  data;           //���������� 
	Struct  LNode   *next;     //����ָ���� 
}LNode; 
typedef  LNode  *LinkList; 
//����Ϊ�����ṹ

LinkList Invert_L( LinkList L ){
	//���õ�����L
	LNode *p ,*q ;//����������ʱָ�����
	if( L&&L->next){ 
		//�������ǿձ�򵥽��ʱ���������еĳ�ͷ���������н��˳������ָ�룬��ǰ����ÿ��������δ�������ժ�£���Ϊ��һ�������뵽��ͷ��������С������Ϳ��Եõ����õ�����
		L = L->next;
		p = L;
		q = p->next;
		p -> next = NULL; //����ʼ����ɴ�ͷ���������ն˽�㣬ԭ���ĵڶ�������Ϊ�µ���ͷ����Ŀ�ʼ���
		
		while (q){ 
			//ÿ��ѭ������ͷ������ĺ�һ������ɴ�ͷ������Ŀ�ʼ���
			p = q; 
			q = q-> next ; 
			p->next = L;
			L = p;
		}
		return L;
	}
	return L; //���ǿձ�򵥽���ֱ�ӷ���ͷָ�롣
	//������Ϊ�ձ��ֻ��һ�����ʱ�������������������ԭ����ͬ��
}
//Invert_L
*/
