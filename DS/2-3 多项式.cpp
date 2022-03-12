/*
��Ŀ��Description����
˳��ջӦ��ʵ������һ���Ϸ�����׺���ʽ��ֵ��������ʽֻ����+��-�������� �ĸ�˫Ŀ���������������������ж����ԡ�ֻ�ܽ����������������㣬֧��С���š��Բ��������Ľ����������������������ȡ����
Ҫ��
��1����ȷ���ͱ��ʽ��
��2�����������������
��3�����������̺�����������
*/


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define  LEN  sizeof(LNode)
typedef struct LNode   {
	//�õ�����洢����ʽ�Ľ��ṹ
	int coef;  //����ʽ��ϵ��
	int exp;   //ָ��
	struct LNode *next; //ָ����һ��Ԫ�ص�ָ�� 
}LNode;
typedef LNode polynomial;

polynomial *create(void) { 
	//��β�巨����һԪ����ʽ������ĺ���
	polynomial *h,*r,*s;
	int c,e;
	h=(polynomial*)malloc(LEN);  //��������ʽ��ͷ��㣬Ϊͷ������洢�ռ�
	r=h; //rָ��ʼ�ն�ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���
	scanf("%d",&c); //����ϵ��
	scanf("%d",&e); //����ָ��
	while(c!=0){ //����ϵ��Ϊ0ʱ����ʾ����ʽ���������
		s=(polynomial *)malloc(LEN); //�����½��
		s->coef=c;
		s->exp=e;   //�����½���ֵ
		r->next=s; //��β�壬�����½��
		r=s;  //rʼ��ָ������ı�β
		scanf("%d",&c);
		scanf("%d",&e);
	}
	r->next=NULL; //��������һ������next��NULL����ʾ�����
	return(h);
}
void Addpolyn(polynomial *pa, polynomial *pb){
	//һԪ����ʽ��Ӻ��������ڽ���������ʽ��ӣ�Ȼ�󽫺Ͷ���ʽ����ڶ���ʽpolya�У���������ʽploybɾ��
	polynomial *p,*q,*pre,*temp;
	p=pa->next;//��p��q�ֱ�ָ��polya��polyb����ʽ�����еĵ�һ�����
	q=pb->next;
	pre=p;    //λ��ָ�룬ָ��Ͷ���ʽpolya
	while(p&&q){ //����������ʽ��δɨ�����ʱ��ִ�����²���
		if(p->exp<q->exp){           //��pָ��Ķ���ʽָ��С��qָ��ָ��
			pre=p;      //��p�����뵽�Ͷ���ʽ��
			p=p->next;
		}
		else if(p->exp==q->exp){    //��ָ����ȣ�����Ӧ��ϵ�����
			p->coef=p->coef+q->coef;
			if(p->coef!=0){
				pre=p;
				p=pre->next;
				temp=q;
				q=q->next;
				delete temp;
			}
			else {    //���ϵ����Ϊ�㣬��ɾ�����p��q������ָ��ָ����һ�����
				pre->next=p->next;
				delete p;
			}
		}
		else{                      //��pָ������qָ��*
			temp=q->next;
			q->next=p;
			pre->next=q;
			pre=q;
			q=temp;
		}
	}
	if(q)  //����ʽB�л���ʣ�࣬��ʣ��Ľ����뵽�Ͷ���ʽ��
		pre->next=q;
	delete pb;
}
void print(polynomial *p){ //�����������ӡ��һԪ����ʽ
	while(p->next!=NULL){
		p=p->next;
		printf("     %d*x^%d",p->coef,p->exp);
	}
}
int main(){       //������
	polynomial *polya,*polyb;
	printf("\nPlease input the ploya include coef && exp:\n");
	polya=create();  //���ý�������������������ʽA
	print(polya);
	printf("\nPlease input the ployb include coef && exp:\n");
	polyb=create();  //ͬ������B
	print(polyb);
	printf("\nSum of the poly is:\n");
	Addpolyn(polya,polyb);    //����һԪ����ʽ��Ӻ���
	print(polya);            //���������������ӡ���*
	printf("\n");
} 


//������������ʽ����㷨��ʱ�临�Ӷ� 
/*
��������ʽ�ġ������͡��������ʽA��n�����ʽB��m�
�㷨ִ��ʱ����Ҫ������whileѭ���Ļ��������ϣ�ִ�д������Ϊ��n+m��
��˸��㷨��ʱ�临�Ӷ�ΪO(n+m)
*/
