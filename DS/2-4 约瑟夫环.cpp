#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct LNode{
	int num;
	LNode *next;
};
LNode *p,*r,*list;

/*���õ���ѭ������ʵ��*/
void joseph(int n, int m){//n����������m����������
	int i;
	//��������
	printf("\n�����˵ı��Ϊ��") ;
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

	p->next=list;//ʹ����ѭ��
	p=list;//pָ��ͷ���
	r=p;

	//xѭ��ɾ�������еĽ�㣬������
	while(p->next!=p){
		for(i=1;i<m;i++){
			r=p;
			p=p->next;
		}
		r->next=p->next;
		printf("\n�����˵ı��Ϊ��%d��",p->num);
		delete p;
		p=r->next;
	}
	printf("\n\n��ʤ�˵ı��Ϊ��%d��\n",p->num);
}

int main(){
	int m,n;
	printf("���������������");
	scanf("%d",&n);
	printf("������������룺");
	scanf("%d",&m);
	joseph(n,m);
	return 0;
}
