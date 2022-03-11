#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct LNode{
	int num;
	LNode *next;
};
LNode *p,*r,*list;

/*利用单向循环链表实现*/
void joseph(int n, int m){//n：总人数；m：报数上限
	int i;
	//创建链表
	printf("\n参与人的编号为：") ;
	for(i=1;i<=n;i++){
		p = new LNode;
		p->num=i;
		if(list==NULL)
			list=p;
		else 
			r->next=p;
		r=p;
		if(i<n) 
			printf("%d,",i);
		else printf("%d\n",i);
	}

	p->next=list;//使链表循环
	p=list;//p指向头结点
	r=p;

	//x循环删除队列中的结点，即出列
	while(p->next!=p){
		for(i=1;i<m;i++){
			r=p;
			p=p->next;
		}
		r->next=p->next;
		printf("\n出局人的编号为：%d号",p->num);
		delete p;
		p=r->next;
	}
	printf("\n\n获胜人的编号为：%d号\n",p->num);
}

int main(){
	int m,n;
	printf("请输入参与人数：");
	scanf("%d",&n);
	printf("请输入出局密码：");
	scanf("%d",&m);
	joseph(n,m);
	return 0;
}
