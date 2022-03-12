#include <iostream>
using namespace std;
//StudybarCommentBegin
#include <stdio.h>
typedef char ElemType;

//�洢�ṹ
typedef struct BiTNode  {
	ElemType	   	data;
	struct BiTNode 	*lchild, *rchild;
} BiTNode; 
typedef BiTNode *BiTree; 
//StudybarCommentEnd


//���������� 
void CreateBiTree(BiTree &BT){
	char ch;
	scanf("%c",&ch);
	if(ch == ' ')
		BT=NULL;
	else{
		BT=new BiTNode;
		BT->data=ch;
		CreateBiTree(BT->lchild);
		CreateBiTree(BT->rchild);
	} 
}

//�������������
void PreOrderBiTree(BiTree T){
	if(T){
		cout<<T->data<<" ";
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}


//�������������
void InOrderBiTree(BiTree T){
	if(T){
		InOrderBiTree(T->lchild);
		cout<<T->data<<" ";
		InOrderBiTree(T->rchild);
	}
}


//�������������
void PostOrderBiTree(BiTree T){
	if(T){
    	PostOrderBiTree(T->lchild);
		PostOrderBiTree(T->rchild);
		cout<<T->data<<" ";
    }
}

//StudybarCommentBegin
int main()
{
	BiTree BT;
	printf("�����������Ķ�����������ո�Ϊ��������\n");
	CreateBiTree(BT);
	printf("����������У�");
	PreOrderBiTree(BT);
	printf("\n����������У�");
	InOrderBiTree(BT);
	printf("\n����������У�");
	PostOrderBiTree(BT);
	printf("\n");
	return 0;
}
//StudybarCommentEnd
