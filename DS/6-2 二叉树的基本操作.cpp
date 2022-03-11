#include <iostream>
using namespace std;
//StudybarCommentBegin
#include <stdio.h>
typedef char ElemType;

//存储结构
typedef struct BiTNode  {
	ElemType	   	data;
	struct BiTNode 	*lchild, *rchild;
} BiTNode; 
typedef BiTNode *BiTree; 
//StudybarCommentEnd


//创建二叉树 
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

//先序遍历二叉树
void PreOrderBiTree(BiTree T){
	if(T){
		cout<<T->data<<" ";
		PreOrderBiTree(T->lchild);
		PreOrderBiTree(T->rchild);
	}
}


//中序遍历二叉树
void InOrderBiTree(BiTree T){
	if(T){
		InOrderBiTree(T->lchild);
		cout<<T->data<<" ";
		InOrderBiTree(T->rchild);
	}
}


//后序遍历二叉树
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
	printf("创建二叉树的二叉链表（输入空格为空树）：\n");
	CreateBiTree(BT);
	printf("先序遍历序列：");
	PreOrderBiTree(BT);
	printf("\n中序遍历序列：");
	InOrderBiTree(BT);
	printf("\n后序遍历序列：");
	PostOrderBiTree(BT);
	printf("\n");
	return 0;
}
//StudybarCommentEnd
